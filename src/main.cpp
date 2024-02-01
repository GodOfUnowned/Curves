#include <cmath>
#include <iostream>
#include <numbers>
#include <memory>
#include <vector>
#include <random>
#include <algorithm>
#include <set>
#include "point.hpp"
#include "circle.hpp"
#include "ellipse.hpp"
#include "helix.hpp"

struct CircleSharedPtrComp
{
  bool operator()(const std::shared_ptr<Circle> &lhs, const std::shared_ptr<Circle> &rhs) const {
    return lhs->get_radius() < rhs->get_radius();
  }
};

void generate_curves(std::vector<std::shared_ptr<Curve>> &curves)
{
  curves.reserve(10);
  std::cout << "Creating curves:" << std::endl;
  for(int i = 1; i < 11; ++i)
    {
      std::random_device rd;
      std::mt19937 e(rd());
      std::uniform_int_distribution<> typedist(1, 3);
      std::uniform_real_distribution<> coordist(-100, 100);
      std::uniform_real_distribution<> radiidist(0, 100);
      
      int curvetype = typedist(e);

      try
	{
	  switch(curvetype)
	    {
	    case 1:
	      {
		float x, y, r;
		x = coordist(e);
		y = coordist(e);
		r = radiidist(e);
		std::cout << "  "  << i << ") Circle with:" <<
		  " x: " << x <<
		  " y: " << y <<
		  " radius: " << r <<
		  std::endl;
		curves.push_back(std::shared_ptr<Circle>(new Circle({x, y, 0}, r)));
		break;
	      }
	    case 2:
	      {
		float x, y, rx, ry;
		x = coordist(e);
		y = coordist(e);
		rx = radiidist(e);
		ry = radiidist(e);
		std::cout << "  "  << i << ") Ellipse with:" <<
		  " x: " << x <<
		  " y: " << y <<
		  " radius by x: " << rx <<
		  " radius by y: " << ry <<
		  std::endl;
		curves.push_back(std::shared_ptr<Ellipse>(new Ellipse({x, y, 0}, rx, ry)));
		break;
	      }
	    case 3:
	      {
		float x, y, z, r, s;
		std::uniform_real_distribution<> stepdist(-100, 100);
		x = coordist(e);
		y = coordist(e);
		z = coordist(e);
		r = radiidist(e);
		s = stepdist(e);
		std::cout << "  "  << i << ") Helix with:" <<
		  " x: " << x <<
		  " y: " << y <<
		  " z: " << z <<
		  " radius: " << r <<
		  " step: " << s <<
		  std::endl;
		curves.push_back(std::shared_ptr<Helix>(new Helix({x, y, z}, r, s)));
		break;
	      }
	    default:
	      std::cout << "  " << "incorect curve id" << std::endl;
	      break;
	    }
	}
      catch(std::invalid_argument &e)
	{
	  std::cout << "    " << e.what() << std::endl;
	}
    }

  std::cout << std::endl;
}

void coor_at(const std::vector<std::shared_ptr<Curve>> &curves, float t)
{
  std::cout << "Point and derivatives at t = " << t << std::endl;
  std::for_each(curves.begin(), curves.end(),
		[=] (const auto& curve)
		{
		  auto point = curve->get_point(t);
		  auto deriv = curve->get_derivative(t);
		  std::cout << point.x_ << " " << point.y_ << " " << point.z_ << std::endl;
		  std::cout << deriv.x_ << " " << deriv.y_ << " " << deriv.z_ << std::endl;
		  std::cout << std::endl;
		});
}

void populate_circles(std::multiset<std::shared_ptr<Circle>, CircleSharedPtrComp> &circles, std::vector<std::shared_ptr<Curve>> &curves)
{
  for(auto it : curves)
    {
      auto curve = std::dynamic_pointer_cast<Circle>(it);

      if(curve != nullptr)
	{
	  circles.insert(curve);
	}
    }
}

float total_sum_of_circles_radii(const std::multiset<std::shared_ptr<Circle>, CircleSharedPtrComp> &circles)
{
  return std::accumulate(circles.begin(), circles.end(), 0.0,
			 [] (float lhs, const std::shared_ptr<Circle> &rhs)
			 {
			   return lhs + rhs->get_radius();
			 });
}

int main(void)
{
  std::vector<std::shared_ptr<Curve>> curves;
  std::multiset<std::shared_ptr<Circle>, CircleSharedPtrComp> circles;

  generate_curves(curves);
  coor_at(curves, std::numbers::pi_v<float> / 4);
  populate_circles(circles, curves);

  std::cout << "Circles by ascending order:" << std::endl;
  for(auto it : circles)
    {
      std::cout << it->get_radius() << std::endl;
    }
  std::cout << std::endl;

  std::cout << "Total sum of circles radii: " << total_sum_of_circles_radii(circles) << std::endl;
  
}

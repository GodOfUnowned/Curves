#include "circle.hpp"
#include "point.hpp"
#include <cmath>
#include <memory>
#include <stdexcept>

Circle::Circle(const Point3D &center, float radius) :
  Curve(center),
  radius_ {radius}
{
  if (radius <= 0) throw std::invalid_argument("radius must be positive");
  if (center.z_ != 0) throw std::invalid_argument("circles cat be placed only on a XoY plane");
}

const Point3D Circle::get_point(float t) const noexcept
{
  return { center_.x_ + radius_ * cosf(t),
	   center_.y_ + radius_ * sinf(t) };
}

const Vector3D Circle::get_derivative(float t) const noexcept
{
  return { radius_ * (-1) * sinf(t),
	   radius_ * cosf(t) };
}

const float Circle::get_radius(void) const noexcept
{
  return radius_;
}


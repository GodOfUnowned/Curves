#include "ellipse.hpp"
#include <cmath>
#include <stdexcept>

Ellipse::Ellipse(const Point3D &center, float radius_x, float radius_y) :
  Curve(center),
  radius_x_ {radius_x},
  radius_y_ {radius_y}
{
  if (radius_x_ <= 0 || radius_y_ <= 0) throw std::invalid_argument("radii must be positive");
  if (center.z_ != 0) throw std::invalid_argument("ellipses can be placed only on a XoY plane");
}

const Point3D Ellipse::get_point(float t) const noexcept
{
  return { center_.x_ + radius_x_ * cosf(t),
	   center_.y_ + radius_y_ * sinf(t) };
}

const Vector3D Ellipse::get_derivative(float t) const noexcept
{
  return { radius_x_ * (-1) * sinf(t),
	   radius_y_ * cosf(t) };
}

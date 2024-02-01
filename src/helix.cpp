#include "helix.hpp"
#include "point.hpp"
#include <cmath>
#include <stdexcept>
#include <numbers>

Helix::Helix(const Point3D &center, float radius, float step) :
  Curve(center),
  radius_ {radius},
  step_ {step / (2 * std::numbers::pi_v<float>)}
{
  if (radius <= 0) throw std::invalid_argument("radius must be positive");
}

const Point3D Helix::get_point(float t) const noexcept
{
  return { center_.x_ + radius_ * cosf(t),
	   center_.y_ + radius_ * sinf(t),
	   step_ * t };
}

const Vector3D Helix::get_derivative(float t) const noexcept
{
  return { radius_ * (-1) * sinf(t),
	  radius_ * cosf(t),
	   step_ };
}

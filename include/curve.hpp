#include "point.hpp"

#ifndef CURVE_HPP
#define CURVE_HPP

class Curve
{
public:
  Curve(const Point3D &center) noexcept:
    center_ {center}
  {}

  virtual const Point3D get_point(float t) const noexcept = 0;
  virtual const Vector3D get_derivative(float t) const noexcept = 0;
  virtual ~Curve() = default;
protected:
  Point3D center_;
};

#endif

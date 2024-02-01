#include "curve.hpp"

#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

class Ellipse : public Curve
{
public:
  Ellipse(const Point3D &center, float radius_x, float radius_y);

  virtual const Point3D get_point(float t) const noexcept override final;

  virtual const Vector3D get_derivative(float t) const noexcept override final;
private:
  float radius_x_;
  float radius_y_;
};

#endif

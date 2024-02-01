#include "curve.hpp"

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle : public Curve
{
public:
  Circle(const Point3D &center, float radius);
  virtual const Point3D get_point(float t) const noexcept override final;
  virtual const Vector3D get_derivative(float t) const noexcept override final;
  const float get_radius(void) const noexcept;
private:
  float radius_;
};

#endif

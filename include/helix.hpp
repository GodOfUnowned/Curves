#include "curve.hpp"

#ifndef HELIX_HPP
#define HELIX_HPP

class Helix : public Curve
{
public:
  Helix(const Point3D &center, float radius, float step);

  virtual const Point3D get_point(float t) const noexcept override final;

  virtual const Vector3D get_derivative(float t) const noexcept override final;
private:
  float radius_;
  float step_;
};

#endif

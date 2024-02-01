#ifndef POINT_HPP
#define POINT_HPP

struct Point3D
{
public:
  float x_;
  float y_;
  float z_;
  
  Point3D(float x, float y, float z = 0);
};

using Vector3D = Point3D;

#endif

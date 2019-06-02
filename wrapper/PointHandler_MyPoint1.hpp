#ifndef __OPENGR_WRAPPER_POINT_HANDLER_EXTLIB1_MYPOINT1_H__
#define __OPENGR_WRAPPER_POINT_HANDLER_EXTLIB1_MYPOINT1_H__

#include "../gr/PointHandler.hpp"
#include "../ext_libs/MyPoint1.hpp"

namespace gr
{


using GRScalar = gr::PointHandler<ext_lib1::MyPoint1>::Scalar;
using MyPoint1Scalar = float;

// Specilization of PointHandler::construct_point(Scalar x, Scalar y, Scalar z)
template<>
inline ext_lib1::MyPoint1 gr::PointHandler<ext_lib1::MyPoint1>::construct_point(GRScalar x, GRScalar y, GRScalar z) {
  ext_lib1::MyPoint1 point;

  point.x = static_cast<MyPoint1Scalar>(x);
  point.y = static_cast<MyPoint1Scalar>(y);
  point.z = static_cast<MyPoint1Scalar>(z);

  return point;
}

// Specilization of PointHandler::construct_point()
template<>
inline ext_lib1::MyPoint1 gr::PointHandler<ext_lib1::MyPoint1>::construct_point() {
  return gr::PointHandler<ext_lib1::MyPoint1>::construct_point(0.f, 0.f, 0.f);
}

//
// getters: x, y, z
//
template<>
inline GRScalar gr::PointHandler<ext_lib1::MyPoint1>::getX(const ext_lib1::MyPoint1& point) {
  return static_cast<GRScalar>(point.x);
}

template<>
inline GRScalar gr::PointHandler<ext_lib1::MyPoint1>::getY(const ext_lib1::MyPoint1& point) {
  return static_cast<GRScalar>(point.y);
}

template<>
inline GRScalar gr::PointHandler<ext_lib1::MyPoint1>::getZ(const ext_lib1::MyPoint1& point) {
  return static_cast<GRScalar>(point.z);
}

//
// setters: x, y, z
//
template<>
inline void gr::PointHandler<ext_lib1::MyPoint1>::setX(ext_lib1::MyPoint1& point, GRScalar x) {
  point.x = static_cast<MyPoint1Scalar>(x);
}

template<>
inline void gr::PointHandler<ext_lib1::MyPoint1>::setY(ext_lib1::MyPoint1& point, GRScalar y) {
  point.y = static_cast<MyPoint1Scalar>(y);
}

template<>
inline void gr::PointHandler<ext_lib1::MyPoint1>::setZ(ext_lib1::MyPoint1& point, GRScalar z) {
  point.z = static_cast<MyPoint1Scalar>(z);
}
}
#endif
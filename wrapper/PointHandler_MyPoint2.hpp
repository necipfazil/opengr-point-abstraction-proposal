#ifndef __OPENGR_WRAPPER_POINT_HANDLER_EXTLIB2_MYPOINT2_H__
#define __OPENGR_WRAPPER_POINT_HANDLER_EXTLIB2_MYPOINT2_H__

#include "../gr/PointHandler.hpp"
#include "../ext_libs/MyPoint2.hpp"

namespace gr {
using GRScalar = gr::PointHandler<ext_lib2::MyPoint2>::Scalar;
using MyPoint2Scalar = double;

// Specilization of PointHandler::construct_point(Scalar x, Scalar y, Scalar z)
template<>
inline ext_lib2::MyPoint2 gr::PointHandler<ext_lib2::MyPoint2>::construct_point(GRScalar x, GRScalar y, GRScalar z) {
  ext_lib2::MyPoint2 point;

  point.x() = static_cast<MyPoint2Scalar>(x);
  point.y() = static_cast<MyPoint2Scalar>(y);
  point.z() = static_cast<MyPoint2Scalar>(z);

  return point;
}

// Specilization of PointHandler::construct_point()
template<>
inline ext_lib2::MyPoint2 gr::PointHandler<ext_lib2::MyPoint2>::construct_point() {
  return gr::PointHandler<ext_lib2::MyPoint2>::construct_point(0.f, 0.f, 0.f);
}

//
// getters: x, y, z
//
template<>
inline GRScalar gr::PointHandler<ext_lib2::MyPoint2>::getX(const ext_lib2::MyPoint2& point) {
  return static_cast<Scalar>(point.x());
}

template<>
inline GRScalar gr::PointHandler<ext_lib2::MyPoint2>::getY(const ext_lib2::MyPoint2& point) {
  return static_cast<Scalar>(point.y());
}

template<>
inline GRScalar gr::PointHandler<ext_lib2::MyPoint2>::getZ(const ext_lib2::MyPoint2& point) {
  return static_cast<Scalar>(point.z());
}

//
// setters: x, y, z
//
template<>
inline void gr::PointHandler<ext_lib2::MyPoint2>::setX(ext_lib2::MyPoint2& point, GRScalar x) {
  point.x() = static_cast<MyPoint2Scalar>(x);
}

template<>
inline void gr::PointHandler<ext_lib2::MyPoint2>::setY(ext_lib2::MyPoint2& point, GRScalar y) {
  point.y() = static_cast<MyPoint2Scalar>(y);
}

template<>
inline void gr::PointHandler<ext_lib2::MyPoint2>::setZ(ext_lib2::MyPoint2& point, GRScalar z) {
  point.z() = static_cast<MyPoint2Scalar>(z);
}

}

#endif
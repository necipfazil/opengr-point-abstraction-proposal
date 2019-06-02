#ifndef __OPENGR_ALGORITHMS_H__
#define __OPENGR_ALGORITHMS_H__

#include "traits.hpp"
#include "PointHandler.hpp"

namespace gr {
namespace algo
{
  using GRScalar = gr::GRTypeTraits::Scalar;

  template<class PointType>
  using pHandle = PointHandler<PointType>;

  template<class PointType>
  GRScalar sum_of_coords(const PointType& point)
  {
    return
      PointHandler<PointType>::getX(point) + 
      PointHandler<PointType>::getY(point) + 
      PointHandler<PointType>::getZ(point);
  }

  template<class PointType>
  void set_0(PointType& point)
  {
    PointHandler<PointType>::setX(point, static_cast<GRScalar>(0.f));
    PointHandler<PointType>::setY(point, static_cast<GRScalar>(0.f));
    PointHandler<PointType>::setZ(point, static_cast<GRScalar>(0.f));
  }
}
}
#endif
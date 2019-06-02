#ifndef __OPENGR_POINT_HANDLER_H__
#define __OPENGR_POINT_HANDLER_H__

#include "traits.hpp"

namespace gr {
//
// PointHandler: All to be specialized with PointType
//
template<class PointType>
class PointHandler {
  public:
    using Scalar = gr::GRTypeTraits::Scalar;

    static inline PointType construct_point();
    static inline PointType construct_point(Scalar x, Scalar y, Scalar z);

    static inline Scalar getX(const PointType& point);
    static inline Scalar getY(const PointType& point);
    static inline Scalar getZ(const PointType& point);

    static inline void setX(PointType& point, Scalar x);
    static inline void setY(PointType& point, Scalar y);
    static inline void setZ(PointType& point, Scalar z);
    /* 
    // To be extended to be meet the needs of OpenGR library..
    inline Scalar x(const PointType& point);
    inline Scalar y(const PointType& point);
    inline Scalar z(const PointType& point);
    ...
    */
};



//
// VectorHandler
//
template<class VectorType>
class VectorHandler {
  // TODO: will follow the same approach as PointHandler
};

//
// ColorHandler
//
template<class ColorType>
class ColorHandler {
  // TODO: will follow the same approach as PointHandler
};

}

#endif
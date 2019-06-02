#include <iostream>

#include "gr/traits.hpp"
#include "gr/Algorithms.hpp"

/*#include "gr/PointHandler.hpp"*/

#include "ext_libs/MyPoint1.hpp"
#include "ext_libs/MyPoint2.hpp"

#include "wrapper/PointHandler_MyPoint1.hpp"
#include "wrapper/PointHandler_MyPoint2.hpp"

int main()
{
  using GRScalar = gr::GRTypeTraits::Scalar;

  // Different point types from different external libraries..
  ext_lib1::MyPoint1 point1;
  point1.x = 1; point1.y = 2; point1.z = 3; 

  ext_lib2::MyPoint2 point2;
  point2.x() = 4; point2.y() = 5; point2.z() = 6; 

  // Do some algorithmic work on the points..
  GRScalar sum_of_coords_p1 = gr::algo::sum_of_coords(point1);
  GRScalar sum_of_coords_p2 = gr::algo::sum_of_coords(point2);

  std::cout << "Sum of coordinates of point1: " << sum_of_coords_p1 << std::endl;
  std::cout << "Sum of coordinates of point2: " << sum_of_coords_p2 << std::endl;
  
  return 0;
}


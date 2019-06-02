# opengr-point-abstraction-proposal

### Files
* [gr/](gr/) Subset of OpenGR library  
  * [gr/PointHandler.hpp](gr/PointHandler.hpp) The declaration of the template type `PointHandler`, whose static functions are to be specialized for point type of any external library for interoperability (Same will be done for vector and color type, or any other type of data that OpenGR use and external library might feed).
  * [gr/Algorithms.hpp](gr/Algorithms.hpp) An example algorithms file, which make use of the template type `PointHandler` when it needs to reach to the attributes of a point. The specialized `PointHandler` functions will be used, therefore, once the functions needed for `PointHandler` are speciliazied, OpenGR will freely make use of attributes of external libraries' point types.  
* [ext_libs/](ext_libs/) External libraries  
  * [ext_libs/MyPoint1.hpp](ext_libs/MyPoint1.hpp) An example point type for an external library.  
  * [ext_libs/MyPoint2.hpp](ext_libs/MyPoint2.hpp) Another example point type for another external library.
* [wrapper/](wrapper/) Wrappers for external libraries' point types  
  * [wrapper/PointHandler_MyPoint1.hpp](wrapper/PointHandler_MyPoint1.hpp) The specializations of `PointHandler` functions for the point type (`MyPoint1`) of external library 1.
  * [wrapper/PointHandler_MyPoint2.hpp](wrapper/PointHandler_MyPoint2.hpp) The specializations of `PointHandler` functions for the point type (`MyPoint2`) of external library 2.  
  

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
  
### Strategy  
We want to allow usage of any point type in OpenGR. In certain parts of the OpenGR library, which attributes of point type we need to use are known. For example, we want to construct points, we want to get points' x, y, z coordinates, or we want to set their coordinates. Therefore, we can define what we need from a point: implementation of a `getX()` function, implementation of a `setY()` function, etc..  

The required functionalities are given inside [gr/PointHandler.hpp](gr/PointHandler.hpp) as static functions - without any implementations. It is the wrapper code's responsibility to specialize those template functions for the point type to use. For example, if one wants to use the point type `MyPoint1` within OpenGR library, s/he needs to write specializations as in [wrapper/PointHandler_MyPoint1.hpp](wrapper/PointHandler_MyPoint1.hpp). The examples of specializations are given inside [wrapper/](wrapper/) folder. The [wrapper/](wrapper/) folder is not really a part of the OpenGR library: it will be needed to be included only when a external point type is used.  

A wrapper (specialization of PointHandler functions) could be written for the existing PointType (gr::Point3D) library, which will let the existing tests/demos work without needing much change. Also, the IO part can remain as is this way.  

The same strategy could be followed for the other types and their attributes that OpenGR certainly needs: `VectorType`, `ColorType` etc. 


### Advantages


### Other Capabilities
Given some basic functions on point types, we can achieve further tasks by using those basic functions. Instead of points, let's think of vectors (geometrically vectors, which yields a direction instead of a position). Given specializations of `VectorHandler::getX()`, `VectorHandler::getY()`, `VectorHandler::getZ()`, and `VectorHandler::construct_vector(Scalar x, Scalar y, Scalar z)` functions, we can simply calculate the length of a vector and construct the normalized version of it with length 1.   Let's say `VectorHandler::get_normalized()` achieves this task. We can define a default implementation for `VectorHandler::get_normalized()` function, which will work for any vector type by making use of specialized functions. However, external libraries could have their optimized way for getting the normalized version of a vector. At this point, the external library could also specialize `VectorHandler::get_normalized()` function for its vector type to increase the performance. This way, we can ensure this: wrapper could be written for external libraries with least amount of effort (by specializing only the required functions), while more effort could be put to increase the performance (by specializing other functions of handlers).

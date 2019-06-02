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
Most certainly, we could have used polymorphism to achieve the same task: we would have had an abstract class, which we would require to be implemented by some wrapper class that handles the adaption for an external libraries' point type. However, this could cause certain problems. First, we would need to make use of virtual functions, which would decrease the performance. In above strategy, we don't use virtual functions - all types and corresponding functions are resolved at compile time. Therefore, we don't suffer from performance decrease due to virtual function resolution.  

The requirements for writing a wrapper is convenient: specialize the PointHandler (or VectorHandler, ColorHandler) functions for your own types. We could list required and optional (in case of possible optimizations, see [Other Capabilities](#other-capabilities) section) functions of PointHandler. Therefore, it will be easy for the future developers to adapt their types to be used in OpenGR library.  

### Other Capabilities
Given some basic functions on point types, we can achieve further tasks by using those basic functions. Instead of points, let's think of vectors (geometrically vectors, which yields a direction instead of a position). Given specializations of `VectorHandler::getX()`, `VectorHandler::getY()`, `VectorHandler::getZ()`, and `VectorHandler::construct_vector(Scalar x, Scalar y, Scalar z)` functions, we can simply calculate the length of a vector and construct the normalized version of it with length 1.   Let's say `VectorHandler::get_normalized()` achieves this task. We can define a default implementation for `VectorHandler::get_normalized()` function, which will work for any vector type by making use of specialized functions. However, external libraries could have their optimized way for getting the normalized version of a vector. At this point, the external library could also specialize `VectorHandler::get_normalized()` function for its vector type to increase the performance. This way, we can ensure this: wrapper could be written for external libraries with least amount of effort (by specializing only the required functions), while more effort could be put to increase the performance (by specializing other functions of handlers).

### Foreseen Changes
The point type `gr::Point3D` or its interface is used pretty much everywhere in the library. For example, to obtain the position of a point, `gr::Point3D::pos()` function is called on point object. Even when the PointType is templated, `pos()` function is assumed to be a member of the class PointType, which worked well when `gr::Point3D` is used. However, with the above strategy, `pointObject.pos()` calls should be replaced by a function like `PointHandler<PointType>::pos(pointObject)` (Remember above strategy: `PointHandler<PointType>::pos(pointObject)` will be required to be specialized by any external point type). Therefore, although it is straightforward, almost all files of the library will need changes.

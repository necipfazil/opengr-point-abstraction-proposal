#ifndef __EXTLIB2_MYPOINT2_H__
#define __EXTLIB2_MYPOINT2_H__

namespace ext_lib2 {

class MyPoint2 {
  private:
    double coords[3];

  public:
    double& x() { return coords[0]; }
    double& y() { return coords[1]; }
    double& z() { return coords[2]; }

    double x() const { return coords[0]; }
    double y() const { return coords[1]; }
    double z() const { return coords[2]; }

};

}

#endif
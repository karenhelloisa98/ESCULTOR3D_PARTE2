#ifndef CUTELLIPSOID_H_INCLUDED
#define CUTELLIPSOID_H_INCLUDED
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutEllipsoid : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~CutEllipsoid();
    void draw(Sculptor &t);
};


#endif // CUTELLIPSOID_H_INCLUDED

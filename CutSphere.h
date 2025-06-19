#ifndef CUTSPHERE_H_INCLUDED
#define CUTSPHERE_H_INCLUDED
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutSphere : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere();
    void draw(Sculptor &t);
};
#endif // CUTSPHERE_H_INCLUDED

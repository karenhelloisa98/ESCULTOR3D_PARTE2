#ifndef PUTSPHERE_H_INCLUDED
#define PUTSPHERE_H_INCLUDED
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class PutSphere : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, radius;
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    ~PutSphere();
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H_INCLUDED

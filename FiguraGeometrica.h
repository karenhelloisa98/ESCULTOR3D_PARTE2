#ifndef FIGURAGEOMETRICA_H_INCLUDED
#define FIGURAGEOMETRICA_H_INCLUDED
#include "Sculptor.h"

class FiguraGeometrica{ // SUPER CLASSE ABSTRATA
protected:
    float r, g, b, a;
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica(){};
    virtual void draw(Sculptor &t)=0;
};


#endif // FIGURAGEOMETRICA_H_INCLUDED

#ifndef FIGURAGEOMETRICA_H_INCLUDED
#define FIGURAGEOMETRICA_H_INCLUDED
#include "Sculptor.h"

class FiguraGeometrica{ // SUPER CLASSE ABSTRATA
protected:
    float r, g, b, a; //as figuras geométricas tem propriedades em comum, como as cores e transparência
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(Sculptor &t)=0; //método virtual puro
};


#endif // FIGURAGEOMETRICA_H_INCLUDED

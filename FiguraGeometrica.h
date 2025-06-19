#ifndef FIGURAGEOMETRICA_H_INCLUDED
#define FIGURAGEOMETRICA_H_INCLUDED
#include "Sculptor.h"

class FiguraGeometrica{ // SUPER CLASSE ABSTRATA
protected:
    float r, g, b, a; //as figuras geom�tricas tem propriedades em comum, como as cores e transpar�ncia
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(Sculptor &t)=0; //m�todo virtual puro
};


#endif // FIGURAGEOMETRICA_H_INCLUDED

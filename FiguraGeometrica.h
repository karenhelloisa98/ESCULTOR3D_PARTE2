#ifndef FIGURAGEOMETRICA_H_INCLUDED
#define FIGURAGEOMETRICA_H_INCLUDED
#include "Sculptor.h"

// SUPER CLASSE ABSTRATA
class FiguraGeometrica{
protected: //AS CLASSES DERIVADAS CONSEGUEM ACESSAR DIRETAMENTE
    float r, g, b, a; //as figuras geom�tricas tem propriedades em comum, como as cores e transpar�ncia
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(Sculptor &t)=0; // M�TODO VIRTUAL PURO
                                      // A FUN��O DRAW RECEBE COMO REFER�NCIA UM OBJETO SCULPTOR
                                      // N�O POSSUI IMPLEMENTA��O AQUI E � OBRIGATORIAMENTE IMPLEMENTADO NAS CLASSES HERDEIRAS
};


#endif // FIGURAGEOMETRICA_H_INCLUDED

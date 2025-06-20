#ifndef FIGURAGEOMETRICA_H_INCLUDED
#define FIGURAGEOMETRICA_H_INCLUDED
#include "Sculptor.h"

// SUPER CLASSE ABSTRATA
class FiguraGeometrica{
protected: //AS CLASSES DERIVADAS CONSEGUEM ACESSAR DIRETAMENTE
    float r, g, b, a; //as figuras geométricas tem propriedades em comum, como as cores e transparência
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(Sculptor &t)=0; // MÉTODO VIRTUAL PURO
                                      // A FUNÇÃO DRAW RECEBE COMO REFERÊNCIA UM OBJETO SCULPTOR
                                      // NÃO POSSUI IMPLEMENTAÇÃO AQUI E É OBRIGATORIAMENTE IMPLEMENTADO NAS CLASSES HERDEIRAS
};


#endif // FIGURAGEOMETRICA_H_INCLUDED

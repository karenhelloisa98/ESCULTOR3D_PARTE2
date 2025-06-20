#ifndef LEITOR_H_INCLUDED
#define LEITOR_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>
#include "FiguraGeometrica.h"

class Leitor{
    protected:
    int dx, dy, dz;
    float r, g, b, a;
public:
    Leitor();
    std::vector<FiguraGeometrica*>interpretador(std::string filename); //L� UM ARQUIVO DE TEXTO COM INSTRU��ES, INTERPRETA CADA LINHA, CRIA OBJETOS
                                                                       //CORRESPONDENTES DO TIPO FIGURA GEOM�TRICA* E RETORNA UM VETOR CONTENDO
                                                                       //TODOS ESSES OBJETOS
    //PERMITEM O ACESSO DAS DIMENS�ES DO ESPA�O 3D DEPOIS QUE O ARQUIVO FOI LIDO
    int getdx();
    int getdy();
    int getdz();
};


#endif // LEITOR_H_INCLUDED

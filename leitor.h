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
    std::vector<FiguraGeometrica*>interpretador(std::string filename); //LÊ UM ARQUIVO DE TEXTO COM INSTRUÇÕES, INTERPRETA CADA LINHA, CRIA OBJETOS
                                                                       //CORRESPONDENTES DO TIPO FIGURA GEOMÉTRICA* E RETORNA UM VETOR CONTENDO
                                                                       //TODOS ESSES OBJETOS
    //PERMITEM O ACESSO DAS DIMENSÕES DO ESPAÇO 3D DEPOIS QUE O ARQUIVO FOI LIDO
    int getdx();
    int getdy();
    int getdz();
};


#endif // LEITOR_H_INCLUDED

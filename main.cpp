#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Sculptor.h"
#include "leitor.h"
#include <vector>

int main()
{
    Sculptor *objeto;
    Leitor parser;
    std::vector<FiguraGeometrica*> figuras;

    figuras = parser.parse("objeto.txt");

    objeto = new Sculptor(parser.getdx(), parser.getdy(), parser.getdz());

    for(size_t i = 0; i < figuras.size(); i++){
        figuras[i] -> draw(*objeto);
    }

    objeto -> writeOFF((char*)"objeto.off");

    for(size_t i = 0; i < figuras.size(); i++){
        delete figuras[i];
    }

    delete objeto;
}

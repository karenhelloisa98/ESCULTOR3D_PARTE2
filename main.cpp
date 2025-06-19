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
    Leitor l;
    std::vector<FiguraGeometrica*> figuras;

    figuras = l.interpretador("objeto.txt");

    objeto = new Sculptor(l.getdx(), l.getdy(), l.getdz());

    for(int i = 0; i < figuras.size(); i++){
        figuras[i] -> draw(*objeto);
    }

    objeto -> writeOFF((char*)"objeto.off");

    for(int i = 0; i < figuras.size(); i++){
        delete figuras[i];
    }

    delete objeto;

    std::cout << "Numero de figuras: " << figuras.size() << std::endl;
}

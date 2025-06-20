#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Sculptor.h"
#include "leitor.h"
#include <vector>

int main()
{
    Sculptor *objeto; //PONTEIRO PARA A ESCULTURA 3D
    Leitor l; //OBJETO PARA LER E INTERPRETAR O ARQUIVO

    std::vector<FiguraGeometrica*> figuras; //VETOR DE PONTEIROS PARA FIGURAS GEOM�TRICAS

    figuras = l.interpretador("objeto.txt"); //CHAMA O M�TODO INTERPRETADOR DA CLASSE LEITOR PASSANDO O NOME DO ARQUIVO

    objeto = new Sculptor(l.getdx(), l.getdy(), l.getdz()); //USA OS VALORES DX, DY, DZ LIDOS PARA CRIAR A MATRIZ 3D QUE ARMAZENAR� OS VOXELS

    for(int i = 0; i < figuras.size(); i++){
        figuras[i] -> draw(*objeto); //PARA CADA FIGURA DO VETOR, CHAMA O M�TODO DRAW PASSANDO O ESCULTOR *OBJETO COMO REFER�NCIA
    }

    objeto -> writeOFF((char*)"objeto.off"); //SALVA O CONTE�DO DO ESCULTOR EM UM ARQUIVO .OFF

    //LIBERA A MEM�RIA ALOCADA
    for(int i = 0; i < figuras.size(); i++){
        delete figuras[i];
    }

    delete objeto;

    std::cout << "Numero de figuras: " << figuras.size() << std::endl;
}

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
    std::vector<FiguraGeometrica*> parse(std::string filename);
    int getdx();
    int getdy();
    int getdz();
};


#endif // LEITOR_H_INCLUDED

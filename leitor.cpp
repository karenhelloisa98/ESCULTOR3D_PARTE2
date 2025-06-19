#include "leitor.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "PutVoxel.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"

using namespace std;

Leitor::Leitor() {}

vector<FiguraGeometrica*> Leitor::parse(string filename) {
    vector<FiguraGeometrica*> figuras;
    string s;
    stringstream ss;
    ifstream inFile;
    inFile.open(filename);

    if (!inFile.is_open()) { // verifica se o arquivo abriu direitinho
        cout << "Não foi possivel abrir " << filename << ".\n" << endl;
        exit(0);
    }

    while (inFile.good()) {
        getline(inFile, s);
        if (inFile.good()) {
            ss.clear();
            ss.str(s);
            ss >> s;

            if (ss.good()) { // push_back vai adicionar uma figura geometrica no final do vetor figuras
                if (s.compare("dim") == 0) { // compara o primeiro termo da linha
                    ss >> dx >> dy >> dz; // atribui os termos para as respectivas variaveis
                }
                else if (s.compare("putVoxel") == 0) {
                    int x, y, z;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figuras.push_back(new PutVoxel(x, y, z, r, g, b, a));

                }
                else if (s.compare("cutVoxel") == 0) {
                    int x, y, z;
                    ss >> x >> y >> z;
                    figuras.push_back(new CutVoxel(x, y, z));

                }
                else if (s.compare("putBox") == 0) {
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figuras.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));

                }
                else if (s.compare("cutBox") == 0) {
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figuras.push_back(new CutBox(x0, x1, y0, y1, z0, z1));

                }
                else if (s.compare("putSphere") == 0) {
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                    figuras.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));

                }
                else if (s.compare("cutSphere") == 0) {
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figuras.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));

                }
                else if (s.compare("putEllipsoid") == 0) {
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                    figuras.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));

                }
                else if (s.compare("cutEllipsoid") == 0) {
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    figuras.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));

                }
            }
        }
    }

    inFile.close();
    return(figuras);
}

int Leitor::getdx(){
    return dx;
}

int Leitor::getdy(){
    return dy;
}

int Leitor::getdz(){
    return dz;
}

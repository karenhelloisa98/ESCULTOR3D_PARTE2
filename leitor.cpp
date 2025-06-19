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

Leitor::Leitor() {
}

vector<FiguraGeometrica*> Leitor::interpretador(string filename) {
    vector<FiguraGeometrica*> figuras;
    string s, token;
    stringstream ss;
    ifstream arquivo;
    arquivo.open(filename);

    if (!arquivo.is_open()) {
        cout << "Não foi possivel abrir " << filename << ".\n" << endl;
        exit(0);
    }

    while (getline(arquivo, s)) {
            ss.clear();
            ss.str(s);
            ss >> token;

            if (ss.good()) {
                if (token.compare("dim") == 0) {
                    ss >> dx >> dy >> dz;
                }
                else if (token.compare("putVoxel") == 0) {
                    int x, y, z;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figuras.push_back(new PutVoxel(x, y, z, r, g, b, a));

                }
                else if (token.compare("cutVoxel") == 0) {
                    int x, y, z;
                    ss >> x >> y >> z;
                    figuras.push_back(new CutVoxel(x, y, z));

                }
                else if (token.compare("putBox") == 0) {
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figuras.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));

                }
                else if (token.compare("cutBox") == 0) {
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figuras.push_back(new CutBox(x0, x1, y0, y1, z0, z1));

                }
                else if (token.compare("putSphere") == 0) {
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                    figuras.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));

                }
                else if (token.compare("cutSphere") == 0) {
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figuras.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));

                }
                else if (token.compare("putEllipsoid") == 0) {
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                    figuras.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));

                }
                else if (token.compare("cutEllipsoid") == 0) {
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    figuras.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));

                }
            }
        }
    arquivo.close();
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

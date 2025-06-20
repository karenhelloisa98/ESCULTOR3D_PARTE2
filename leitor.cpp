#include "leitor.h"
#include <iostream> //BIBLIOTECA PARA TRABALHAR COM A SAÍDA NO TERMINAL COUT
#include <string>   //BIBLIOTECA PARA TRABALHAR COM STRINGS
#include <fstream>  //BIBLIOTECA PARA ABRIR E LER ARQUIVOS COM IFSTREAM
#include <sstream>  //BIBLIOTECA PARA MANIPULAR TEXTO COMO FLUXO (STRINGSTREAM)
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

//MÉTODO QUE RECEBE O NOME DO ARQUIVO COM COMANDOS
//RETORNA UM VETOR CONTENDO PONTEIROS PARA OBJETOS FIGURA GEOMÉTRICA
vector<FiguraGeometrica*> Leitor::interpretador(string filename) {

    vector<FiguraGeometrica*> figuras; //VETOR ONDE SERÃO ARMAZENADAS AS FIGURAS LIDAS DO ARQUIVO
    string s, comando;                   //S ARMAZENA CADA LINHA INTEIRA DO ARQUIVO
                                       //TOKEN ARMAZENA A PRIMEIRA PALAVRA DA LINHA (DEFINE O COMANDO)
    stringstream ss;                   //OBJETO QUE TRANSFORMA UMA STRING EM UM FLUXO DE SAÍDA >> PARA EXTRAIR OS VALORES DA LINHA

    ifstream fin;                      //ABRE O ARQUIVO DE ENTRADA USANDO O NOME FILENAME
    fin.open(filename);

    if (!fin.is_open()) {              //VERIFICA SE O ARQUIVO ABRIU CORRETAMENTE
        cout << "Não foi possivel abrir " << filename << ".\n" << endl;
        exit(0);
    }

    while (getline(fin, s)) { //LÊ UMA LINHA DO ARQUIVO E ARMAZENA EM S. REPETE ATÉ O FINAL DO ARQUIVO
            ss.clear(); //LIMPA O STRINGSTREAM
            ss.str(s);  //TRANSFORMA A STRING EM UM FLUXO DE DADOS, PERMITINDO USAR >> PARA EXTRAIR VALORES
            ss >> comando;//LÊ A PRIMEIRA PALAVRA DA LINHA, ISTO É, O COMANDO

            if (ss.good()) {
                if (comando.compare("dim") == 0) {
                    ss >> dx >> dy >> dz;
                }
                else if (comando.compare("putvoxel") == 0) {
                    int x, y, z;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figuras.push_back(new PutVoxel(x, y, z, r, g, b, a)); //INSTANCIA UM NOVO OBJETO DA CLASSE PUTVOXEL. COMO ELE HERDA DE FIGURA GEOMETRICA,
                                                                          //ENTÃO PODE SER ARMAZENADO NO VETOR

                }
                else if (comando.compare("cutvoxel") == 0) {
                    int x, y, z;
                    ss >> x >> y >> z;
                    figuras.push_back(new CutVoxel(x, y, z));

                }
                else if (comando.compare("putbox") == 0) {
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figuras.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));

                }
                else if (comando.compare("cutbox") == 0) {
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figuras.push_back(new CutBox(x0, x1, y0, y1, z0, z1));

                }
                else if (comando.compare("putsphere") == 0) {
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                    figuras.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));

                }
                else if (comando.compare("cutsphere") == 0) {
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figuras.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));

                }
                else if (comando.compare("putellipsoid") == 0) {
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                    figuras.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));

                }
                else if (comando.compare("cutellipsoid") == 0) {
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    figuras.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));

                }
            }
        }
    fin.close(); //FECHA O ARQUIVO
    return(figuras); //RETORNA O VETOR COM TODAS AS FIGURAS LIDAS E CRIADAS
    }

//MÉTODOS QUE PERMITEM ACESSAS AS DIMENSÕES DO ESCULTOR DEPOIS DA LEITURA DO ARQUIVO
int Leitor::getdx(){
    return dx;
}

int Leitor::getdy(){
    return dy;
}

int Leitor::getdz(){
    return dz;
}

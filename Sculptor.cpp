#include "Sculptor.h"
#include "Voxel.h"
#include <fstream>
#include <iomanip>
#include <iostream>

//MÉTODO CONSTRUTUTOR DA CLASSE
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

    //ALOCAÇÃO DA MEMÓRIA
    v = new Voxel **[nx];

    for(int i=0; i<nx; i++){
        v[i] = new Voxel *[ny];
            for (int j=0; j<ny; j++){
                v[i][j] = new Voxel [nz];
        }
    }

    //INICIALIZAÇÃO DOS VOXELS
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
                v[i][j][k].show = false;
            }
        }
    }
}

//MÉTODO DESTRUTOR DA CLASSE
Sculptor::~Sculptor()
{
        for(int i=0;i<nx;i++){
                for(int j=0;j<ny;j++){
                    delete [] v[i][j];
            }
            delete [] v[i];
        }
        delete [] v;
}

//DEFINE A ATUAL COR DO DESENHO
void Sculptor::setColor(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

//ATIVA O VOXEL NA POSIÇÃO (X,Y,Z) FAZENDO SHOW = TRUE E ATRIBUI AO MESMO A COR ATUAL DE DESENHO
void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;

}

//DESATIVA O VOXEL NA POSIÇÃO (X,Y,Z) FAZENDO SHOW = FALSE
void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].show = false;
}

//ATIVA TODOS OS VOXELS NO INTERVALO E ATRIBUI AOS MESMOS A COR ATUAL DE DESENHO)
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=x0;i<x1;i++){
        for(int j=y0;j<y1;j++){
            for(int k=z0;k<z1;k++){
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
                v[i][j][k].show = true;
            }
        }
    }
}

//DESATIVA TODOS OS VOXELS NO INTERVALO E ATRIBUI AOS MESMOS A COR ATUAL DE DESENHO
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=x0;i<x1;i++){
        for(int j=y0;j<y1;j++){
            for(int k=z0;k<z1;k++){
                v[i][j][k].show = false;
            }
        }
    }
}

//ATIVA OS VOXELS PARA DESENHAR A ESFERA
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
        putEllipsoid(xcenter, ycenter, zcenter, radius, radius, radius);
}

//DESATIVA OS VOXELS PARA DESENHAR A ESFERA
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
        cutEllipsoid(xcenter, ycenter, zcenter, radius, radius, radius);
}

//ATIVA OS VOXELS PARA DESENHAR A ELIPSE
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int x0 = xcenter - rx;
    int x1 = xcenter + rx;
    int y0 = ycenter - ry;
    int y1 = ycenter + ry;
    int z0 = zcenter - rz;
    int z1 = xcenter + rz;

    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                if (i >= 0 && i < nx && j >= 0 && j < ny && k >= 0 && k < nz) {

                    float dx = (float)(i - xcenter) / rx;
                    float dy = (float)(j - ycenter) / ry;
                    float dz = (float)(k - zcenter) / rz;

                    if ((dx * dx + dy * dy + dz * dz) <= 1.0) {
                        putVoxel(i, j, k);
                    }
                }
            }
        }
    }
}

//DESATIVA OS VOXELS PARA CORTAR A ESFERA
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int x0 = xcenter - rx;
    int x1 = xcenter + rx;
    int y0 = ycenter - ry;
    int y1 = ycenter + ry;
    int z0 = zcenter - rz;
    int z1 = xcenter + rz;

    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                if (i >= 0 && i < nx && j >= 0 && j < ny && k >= 0 && k < nz) {

                    float dx = (float)(i - xcenter) / rx;
                    float dy = (float)(j - ycenter) / ry;
                    float dz = (float)(k - zcenter) / rz;

                    if ((dx * dx + dy * dy + dz * dz) <= 1.0) {
                        cutVoxel(i, j, k);
                    }
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename)
{
    std::ofstream fout;

    fout.open(filename);
    if (!fout.is_open())
    {
        std::cout<<"Arquivo não aberto!\n";
        exit(1);
    }
    std::cout<<"Arquivo gravado com sucesso!\n"<<std::endl;

    fout << "OFF\n"; //PRIMEIRA LINHA DO ARQUIVO

    int nvoxels=0;
    for (int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].show == true){
                    nvoxels++; //CONTABILIZAÇÃO DA QUANTIDADE DE VOXELS INDIVIDUAIS
                }
            }
        }
    }
    fout << nvoxels * 8 << " " << nvoxels * 6 << " 0\n"; //SEGUNDA LINHA DO ARQUIVO (VÉRTICES, FACES, ARESTAS)


    //DEFINIÇÃO DAS COORDENADAS NO ESPAÇO
    for (int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].show){
                    fout <<i - 0.5 <<" "<<j + 0.5<<" "<<k - 0.5<< std::endl; //P0
                    fout <<i - 0.5 <<" "<<j - 0.5<<" "<<k - 0.5<< std::endl; //P1
                    fout <<i + 0.5 <<" "<<j - 0.5<<" "<<k - 0.5<< std::endl; //P2
                    fout <<i + 0.5 <<" "<<j + 0.5<<" "<<k - 0.5<< std::endl; //P3
                    fout <<i - 0.5 <<" "<<j + 0.5<<" "<<k + 0.5<< std::endl; //P4
                    fout <<i - 0.5 <<" "<<j - 0.5<<" "<<k + 0.5<< std::endl; //P5
                    fout <<i + 0.5 <<" "<<j - 0.5<<" "<<k + 0.5<< std::endl; //P6
                    fout <<i + 0.5 <<" "<<j + 0.5<<" "<<k + 0.5<< std::endl; //P7
                }
            }
        }
    }

    //DEFINIÇÃO DAS FACES
    int vertice = 0;
    for (int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].show){
                    fout << 4 << " "<< vertice+0 << " "<< vertice+3 << " "<< vertice+2 << " "<< vertice+1 << " "<< std::fixed << std::setprecision(1)
                    << v[i][j][k].r << " "<< v[i][j][k].g << " "<< v[i][j][k].b << " "<< v[i][j][k].a << std::endl; // FACE 1

                    fout<<4 <<" "<< vertice+4<<" "<< vertice+5<< " "<<vertice+6<<" "<<vertice+7<<" "<< std::fixed << std::setprecision(1)
                    << v[i][j][k].r<< " "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl; //FACE 2

                    fout<<4 <<" "<< vertice+0<<" "<< vertice+1<< " "<<vertice+5<<" "<<vertice+4<<" "<< std::fixed<< std::setprecision(1)
                     << v[i][j][k].r<< " "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl; //FACE 3

                    fout<<4 <<" "<< vertice+0<<" "<< vertice+4<< " "<<vertice+7<<" "<<vertice+3<<" "<< std::fixed<< std::setprecision(1)
                    << v[i][j][k].r<< " "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl; //FACE 4

                    fout<<4 <<" "<< vertice+7<<" "<< vertice+6<< " "<<vertice+2<<" "<<vertice+3<<" "<<std::fixed<< std::setprecision(1)
                    << v[i][j][k].r<< " "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl; //FACE 5

                    fout<<4 <<" "<< vertice+1<<" "<< vertice+2<< " "<<vertice+6<<" "<<vertice+5<<" "<<std::fixed<< std::setprecision(1)
                    << v[i][j][k].r<< " "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl; //FACE 6

                    vertice = vertice+8;
                }
            }
        }
    }
    fout.close();
}




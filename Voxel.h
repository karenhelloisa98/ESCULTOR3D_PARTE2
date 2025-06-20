#ifndef VOXEL_H_INCLUDED
#define VOXEL_H_INCLUDED

//REPRESENTA O BLOCO UNITÁRIO DO ESCULTOR ("PIXEL 3D")
struct Voxel {
    float r,g,b; // Cores
    float a; // Transparencia
    bool show; // Incluido ou nao
};


#endif // VOXEL_H_INCLUDED

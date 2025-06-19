#ifndef PUTVOXEL_H_INCLUDED
#define PUTVOXEL_H_INCLUDED
#include "Sculptor.h"
#include "FiguraGeometrica.h"

class PutVoxel : public FiguraGeometrica{
protected:
    int x, y, z;
public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~PutVoxel();
    void draw(Sculptor &t);
};


#endif // PUTVOXEL_H_INCLUDED

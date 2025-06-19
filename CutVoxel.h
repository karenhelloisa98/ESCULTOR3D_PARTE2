#ifndef CUTVOXEL_H_INCLUDED
#define CUTVOXEL_H_INCLUDED
#include "Sculptor.h"
#include "FiguraGeometrica.h"

class CutVoxel : public FiguraGeometrica{
protected:
    int x, y, z;
public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel();
    void draw(Sculptor &t);
};


#endif // CUTVOXEL_H_INCLUDED

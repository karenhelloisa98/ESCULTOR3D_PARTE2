#include "CutVoxel.h"

CutVoxel::CutVoxel(int x, int y, int z){
     this->x = x;
     this->y = y;
     this->z = x;
}
CutVoxel::~CutVoxel(){

}
void CutVoxel::draw(Sculptor &t){
    t.cutVoxel(x,y,z);
}

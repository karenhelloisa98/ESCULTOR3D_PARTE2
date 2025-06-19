#include "PutEllipsoid.h

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, int r, int g, int b, int a){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;

}

PutEllipsoid::~PutEllipsoid(){

}

void PutEllipsoid::draw(Sculptor &t){
    t.setColor(r, g, b, a)
    t.putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz)
}

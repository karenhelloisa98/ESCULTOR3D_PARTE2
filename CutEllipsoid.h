#ifndef CUTELLIPSOID_H_INCLUDED
#define CUTELLIPSOID_H_INCLUDED

class CutEllipsoid : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter;
public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~CutEllipsoid();
    void draw(Sculptor &t);
};


#endif // CUTELLIPSOID_H_INCLUDED

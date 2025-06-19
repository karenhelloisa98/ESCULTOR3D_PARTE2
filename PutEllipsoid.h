#ifndef PUTELLIPSOID_H_INCLUDED
#define PUTELLIPSOID_H_INCLUDED

class PutEllipsoid : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    ~PutEllipsoid();
    void draw(Sculptor &t);
};


#endif // PUTELLIPSOID_H_INCLUDED

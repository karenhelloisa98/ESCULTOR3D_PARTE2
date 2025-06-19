#ifndef CUT_ELLIPSOID_H_INCLUDED
#define CUT_ELLIPSOID_H_INCLUDED

class CutEllipsoid : public FiguraGeometrica{
protected:
    int x, y, z;
public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~CutEllipsoid();
    void draw(Sculptor &t);
};


#endif // CUT_ELLIPSOID_H_INCLUDED

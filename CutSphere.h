#ifndef CUTSPHERE_H_INCLUDED
#define CUTSPHERE_H_INCLUDED

class CutSphere : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere();
    void draw(Sculptor &t);
};
#endif // CUTSPHERE_H_INCLUDED

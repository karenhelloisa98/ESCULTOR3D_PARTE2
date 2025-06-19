#ifndef PUTSPHERE_H_INCLUDED
#define PUTSPHERE_H_INCLUDED

class PutSphere : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter;
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    ~PutSphere();
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H_INCLUDED

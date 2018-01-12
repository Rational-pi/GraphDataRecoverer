#ifndef REMAPER2D_H
#define REMAPER2D_H

#include <vector>

class Remaper2D{
    float scale;
    float offset;
    std::vector<float> _from;
    std::vector<float> _to;
public:
    Remaper2D(){}
    void feed(float from,float to);
    float remap(float from);
private:
    void calibrate(float from1,float to1,float from2,float to2);
};

#endif // REMAPER2D_H

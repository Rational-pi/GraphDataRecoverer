#include "remaper2d.h"

Remaper2D::Remaper2D()
{

}

void Remaper2D::calibrate(float from1, float to1, float from2, float to2){
    scale=(from2-from1)/(to2-to1);
    offset=to1-from1/scale;
}

void Remaper2D::feed(float from, float to){
    _from.push_back(from);
    _to.push_back(to);
    if (this->_from.size()==2){
        this->calibrate(_from[0],_to[0],_from[1],_to[1]);
        _from.clear();
        _to.clear();
    }
}

float Remaper2D::remap(float from){
    return from/scale+offset;
}

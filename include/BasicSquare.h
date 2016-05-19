#ifndef BASICSQUARE_H
#define BASICSQUARE_H

#include "Image.h"

#include "SceneObject.h"
#include "Vector2.h"
#include <vector>

class BasicSquare : public SceneObject
{
private:
    Image *_image;
    float _speed;
    std::vector< std::vector< int > > _shape;
    unsigned int _hPos, _vPos;
    Vector2 _position;//directly related to h_pos and v_pos, maybe useless
    Vector2 _destination;//directly related to grid
public:
    BasicSquare();
    ~BasicSquare();

    void Draw();
    void Update();

};


#endif // BASICSQUARE_H


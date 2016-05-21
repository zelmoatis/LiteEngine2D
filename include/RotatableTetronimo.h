#ifndef ROTATABLE_TETRONIMO_H
#define ROTATABLE_TETRONIMO_H

#include "Tetronimo.h"
#include "Image.h"
#include "Vector2.h"

class RotatableTetronimo: public Tetronimo{
protected:
    Image *_image;
    Vector2 _position;//directly related to h_pos and v_pos, maybe useless
    Vector2 _destination;//directly related to grid
    unsigned int _rotation;//ranges from 0 to 3;
    void CyclicRoll(int &a, int &b, int &c, int &d);
public:
    RotatableTetronimo();
    virtual ~RotatableTetronimo();
    virtual void Draw();
    virtual void Update();
    virtual void RotateLeft();
    virtual void RotateRight();
};

#endif // ROTATABLE_TETRONIMO_H


#ifndef ROTATABLE_TETROMINO_H
#define ROTATABLE_TETROMINO_H

#include "Tetromino.h"
#include "Image.h"
#include "Vector2.h"

class RotatableTetromino: public Tetromino{
protected:
    Image *_image[4];
    Vector2 _position;//directly related to h_pos and v_pos, maybe useless
    Vector2 _destination;//directly related to grid
    unsigned int _rotation;//ranges from 0 to 3;
    void DrawShadow();
public:
    RotatableTetromino();
    virtual ~RotatableTetromino();
    virtual void Draw();
    virtual void Update();
    virtual void RotateLeft();
    virtual void RotateRight();

};

#endif // ROTATABLE_TETROMINO_H


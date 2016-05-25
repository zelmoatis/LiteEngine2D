#ifndef PIECEGENERATOR_H
#define PIECEGENERATOR_H


#include "SceneObject.h"
#include "Tetromino.h"
#include "Vector2.h"
#include "Image.h"
#include "Node.h"


class PieceGenerator: public SceneObject{

    Node *_front;
    Node *_end;
    unsigned int _max;
    Vector2 _position;
    Image * _images[2];
    static PieceGenerator* _PGEN_instance;
    PieceGenerator();
    ~PieceGenerator();
public:
    static PieceGenerator * Instance();
    Tetromino* PopPiece();
    void Draw();
    void Update();
    void show_list();
};



#endif // PIECEGENERATOR_H

#ifndef PIECEGENERATOR_H
#define PIECEGENERATOR_H


#include "SceneObject.h"
#include "Tetromino.h"
#include "Vector2.h"
#include "Node.h"


class PieceGenerator: public SceneObject{

    Node *_front;
    Node *_end;
    Vector2 _position;
    unsigned int _max;
    static PieceGenerator* _PGEN_instance;
    PieceGenerator();
    PieceGenerator& operator=(const PieceGenerator&);
    PieceGenerator(const PieceGenerator&);
    ~PieceGenerator();
    void Clear();
public:
    static PieceGenerator * Instance();
    Tetromino* PopPiece();
    void Draw();
    void Update();
    void show_list();
    void Reset();

};



#endif // PIECEGENERATOR_H

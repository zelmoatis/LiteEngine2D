#ifndef PIECEGENERATOR_H
#define PIECEGENERATOR_H


#include "SceneObject.h"
#include "Tetromino.h"
#include "Vector2.h"
#include "Node.h"
#include <map>


class PieceGenerator: public SceneObject{

    static PieceGenerator* _PGEN_instance;
    PieceGenerator();
    PieceGenerator& operator=(const PieceGenerator&);
    PieceGenerator(const PieceGenerator&);
    ~PieceGenerator();
    std::map<std::string, Tetromino*(*)()> _pieceMap;
    std::vector<std::string> _pieceNames;
    Tetromino* PieceCreator(const std::string& pieceName);
public:
    static PieceGenerator * Instance();
    Tetromino* NumberGetPiece(int nr);
    unsigned int PieceTypes();
    void Register( const std::string& pieceName, Tetromino* (*Create)(void) );

};



#endif // PIECEGENERATOR_H

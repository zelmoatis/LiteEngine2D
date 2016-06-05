#include "PieceGenerator.h"
#include <time.h>
#include <cstdio>
#include "Tetromino.h"
#include "BackgroundGrid.h"
#include "ResourceManager.h"
#include "Screen.h"
#include "Node.h"

PieceGenerator* PieceGenerator:: _PGEN_instance = 0;

PieceGenerator* PieceGenerator::Instance(){
    if(!_PGEN_instance)
    {
        _PGEN_instance = new PieceGenerator;
    }
    return _PGEN_instance;
}

Tetromino* PieceGenerator::NumberGetPiece(int nr){
return PieceCreator(_pieceNames[nr-1]);
}

unsigned int PieceGenerator::PieceTypes(){
return _pieceNames.size();
}

PieceGenerator::PieceGenerator(){

}

PieceGenerator::~PieceGenerator(){
    _pieceMap.clear();
    _pieceNames.clear();
}


void PieceGenerator::Register( const std::string& pieceName, Tetromino*(*Create)(void) ){

if(_pieceMap.empty())
    {_pieceMap[pieceName] = Create;
    _pieceNames.push_back(pieceName);
    return;
    }
std::map<std::string, Tetromino*(*)()>::iterator it;
it = _pieceMap.find(pieceName);
if(it == _pieceMap.end())
    {_pieceMap[pieceName] = Create;
    _pieceNames.push_back(pieceName);
    }
}

Tetromino* PieceGenerator::PieceCreator( const std::string& pieceName ){
std::map<std::string, Tetromino*(*)()>::iterator it;
it = _pieceMap.find(pieceName);
if( it != _pieceMap.end() )
    return it->second();
return NULL;
}

#ifndef PLAYER_H
#define PLAYER_H

#include "SceneObject.h"
#include <string>

class Player: public SceneObject{
    std::string _name;
    unsigned int _line;
    unsigned int _piece;
    unsigned int _startMS;

public:
    Player();
    ~Player();
    void Update();
    void Draw();
    void SetName(std::string& name);
    void SetStart( unsigned int startMS );
    unsigned int GetTime();
    unsigned int GetStart();
    unsigned int GetPiece();
    unsigned int GetLine();
    std::string GetName();
};
#endif // PLAYER_H

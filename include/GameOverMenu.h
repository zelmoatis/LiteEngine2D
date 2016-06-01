#ifndef GAMEOVERMENU_H
#define GAMEOVERMENU_H

#include "LayoutManager.h"
#include "SceneObject.h"
#include <vector>
#include <map>
#include <string>

class GameOverMenu: public SceneObject{
private:
    static GameOverMenu* _GOM_Instance;
    GameOverMenu();
    GameOverMenu(const GameOverMenu&);
    GameOverMenu& operator=(const GameOverMenu&);
    ~GameOverMenu();
    std::map<std::string, int> _buttonMap;
    std::vector<bool> _state;
    LayoutManager* _menu;
    Vector2 _position;
    Image* _image;
public:
    static GameOverMenu* Instance();
    void Update();
    void Draw();
    bool GetState( std::string );
};

#endif // GAMEOVERMENU_H

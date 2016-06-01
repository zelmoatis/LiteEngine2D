#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "LayoutManager.h"
#include "SceneObject.h"
#include <vector>
#include <map>
#include <string>

class PauseMenu: public SceneObject{
private:
    static PauseMenu* _PM_Instance;
    PauseMenu();
    PauseMenu(const PauseMenu&);
    PauseMenu& operator=(const PauseMenu&);
    ~PauseMenu();
    std::map<std::string, int> _buttonMap;
    std::vector<bool> _state;
    LayoutManager* _menu;
    Vector2 _position;
    Image* _image;
public:
    static PauseMenu* Instance();
    void Update();
    void Draw();
    bool GetState( std::string );
};

#endif // PAUSEMENU_H

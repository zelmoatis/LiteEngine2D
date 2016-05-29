#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "LayoutManager.h"
#include "SceneObject.h"

class PauseMenu: public SceneObject{
private:
    static PauseMenu* _PM_Instance;
    PauseMenu();
    PauseMenu(const PauseMenu&);
    PauseMenu& operator=(const PauseMenu&);
    ~PauseMenu();
    bool _state;//because it's only one button
    LayoutManager* _menu;
    Vector2 _position;
    Image* _image;
public:
    static PauseMenu* Instance();
    void Update();
    void Draw();
    bool GetState();//if there were more buttons, this would return the state of only one of them

};

#endif // PAUSEMENU_H

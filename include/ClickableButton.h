#ifndef CLICKABLEBUTTON_H
#define CLICKABLEBUTTON_H

#include "SceneObject.h"
#include "Vector2.h"
#include "Image.h"
#include <string>

class ClickableButton: public SceneObject{
private:
    std::string _name;
    Vector2 _position;
    Image * _image;
    bool _activated;
public:
    ClickableButton();
    ClickableButton( const std::string& name, Image * image );
    ~ClickableButton();
    virtual void Draw();
    virtual void Update();
    void SetPosition( const Vector2& position );
    bool Activated();
    unsigned int GetHeight();
    unsigned int GetWidth();
    Vector2 GetPosition();
    std::string GetName();
    void Reset();
    //needs some more work
};

#endif // CLICKABLEBUTTON_H

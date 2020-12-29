#include "Button.h"

#include "../../AlClasses/AlMouse.h"

Button::Button()
{
    x=0;y=0;h=0;w=0;text="";
}

Button::~Button()
{
    
}

void Button::setFont(std::string fontPath,int size)
{
    font.LoadFont(fontPath,size,0);
}

bool Button::isClicked()
{
    if(AlMouse::getButton()==AlMouse::LClick)
    {
        if(AlMouse::isContained(x,y,w,h))
            return true;
    }
    return false;
}

void Button::setSize(int x,int y,int w,int h)
{
    this->x=x;
    this->y=y;
    this->h=h;
    this->w=w;
}

void Button::setText(std::string text)
{
    this->text=text;
}

void Button::draw()
{
    AlDrawable::drawRectangle(x,y,w+x,h+y,color,3);
    font.drawText(textColor,x+(w/2),y,text);
}

void Button::setColor(Color color)
{
    this->color=color;
}

void Button::setTextColor(Color textcolor)
{
    this->textColor=textcolor;
}
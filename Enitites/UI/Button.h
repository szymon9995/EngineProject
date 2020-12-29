#pragma once

#include "../../AlClasses/AlFont.h"
#include "../../AlClasses/AlDrawable.h"

class Button
{
private:
   int x,y;
   int w,h;
   AlFont font;
   std::string text;
   Color color = WHITE;
   Color textColor = RED;
public:
    Button();
    ~Button();

    void setFont(std::string fontPath,int size);
    bool isClicked();
    void setSize(int x,int y,int w,int h);
    void setText(std::string text);
    void setColor(Color color);
    void setTextColor(Color color);
    void draw();
};

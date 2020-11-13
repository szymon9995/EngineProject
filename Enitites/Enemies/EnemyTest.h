#include "../../AlAbstract/Entity.h"
#include "../../AlClasses/AlKeyboard.h"
#include "../../AlClasses/AlDrawable.h"

class EnemyTest : public Entity
{
private:
    int xs,ys;
    int speed;

    bool rev;
public:
    EnemyTest(int x, int y, int w, int h,int speed);
    ~EnemyTest();

    void update();
    void draw();
};

EnemyTest::EnemyTest(int x, int y, int w, int h,int speed)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->speed=speed;
    xs=x;
    ys=y;
    rev = false;
}

EnemyTest::~EnemyTest()
{

}

void EnemyTest::update()
{
    if(x<xs+200 && rev==false)
        x+=speed;
    else
        x-=speed;

    if(x>xs+195)
        rev=true;
    else if(x<xs)
        rev=false;
}

void EnemyTest::draw()
{
    AlDrawable::drawFilledRectangle(x,y,x+w,y+h,AlDrawable::GREEN);
}
#include "TestScene.h"

TestScene::TestScene()
{

}

TestScene::~TestScene()
{
    OnDestroy();
}

void TestScene::Draw()
{
    //Tyczawsowo
    player.draw();
    //////
    contener.Draw();
}

void TestScene::Update()
{
     //Tyczawsowo
    player.update();
    //////
    contener.Update();
}
void TestScene::OnDestroy()
{
    contener.Unload();
}

void TestScene::OnCreate()
{
    player.LoadPlayer(150,150,50,50);
    //contener.Register(&player);
    for(int i=0;i<16;i++)
            contener.Register(new Tile(50*i,550,50,50,&player)); 
    contener.Register(new Tile(750,500,50,50,&player));
    contener.Register(new Tile(650,450,50,50,&player));
    contener.Register(new Tile(550,400,50,50,&player));
    contener.Register(new EnemyBat(500,400,&player));
    contener.Register(new HpBar(50,50,&player));
    contener.Register(new EnemyZombie(300,490,400,&player));
}
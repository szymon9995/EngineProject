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
    camera.UpdateCameraBackround();
    hpBar.draw();
    camera.UpdateCameraForeground();
    player.draw();
    contener.Draw();
}

void TestScene::Update()
{

    player.update();
    hpBar.update();

    contener.Update();

}
void TestScene::OnDestroy()
{
    contener.Unload();
}

void TestScene::OnCreate()
{
    std::string scene_name = "test";
    SetPlayer(scene_name);
    SetUI(scene_name);
    CreateTiles(scene_name);
    SetEnemies(scene_name);

    camera.setCameraScreenSize(800,600);
    camera.setCameraToPlayer(&player);
}

void TestScene::CreateTiles(std::string scene_name)
{
    std::vector<int> tiles = sceneConfig.getTiles(scene_name);
    int ts = sceneConfig.getTileSize();
    int j=0;
    int i=0;
    size_t l=0;
    while(tiles.size()>l)
    {
        int x = tiles.at(l);
        l++;

        if(x==-1)
        {
            j++;
            i=0;
            continue;
        }
        else if(x!=0)
            contener.Register(new Tile(i*ts,j*ts,ts,ts,&player));
        i++;
    }
}

void TestScene::SetEnemies(std::string scene_name)
{
    contener.Register(new EnemyBat(500,400,&player));
    contener.Register(new EnemyZombie(300,490,400,&player));
}

void TestScene::SetPlayer(std::string scene_name)
{
    int x=sceneConfig.getPlayerX(scene_name);
    int y=sceneConfig.getPlayerY(scene_name);
    player.LoadPlayer(x,y,50,50);
}

void TestScene::SetUI(std::string scene_name)
{
    //contener.Register(new HpBar(50,50,&player));
    int x = sceneConfig.getHpBarX();
    int y = sceneConfig.getHpBarY();
    hpBar.setVar(x,y,&player);
}

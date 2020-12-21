#include "TestScene.h"

TestScene::TestScene(SceneManager* manager)
{
    this->manager=manager;
}

TestScene::~TestScene()
{
    OnDestroy();
}

void TestScene::Draw()
{
    camera.UpdateCameraForeground();
    contener.Draw();
    player.draw();
    exitTile->draw();
    camera.UpdateCameraBackround();
    hpBar.draw();
}

void TestScene::Update()
{

    player.update();
    exitTile->update();
    hpBar.update();

    contener.Update();

    if(exitTile->isNextLevel())
        GoNextScene();

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
            contener.Register(Tile::getTile(i*ts,j*ts,ts,ts,&player,x));
        i++;
    }

    int x=sceneConfig.getExitX(scene_name);
    int y=sceneConfig.getExitY(scene_name);

    exitTile = new DoorTile(x,y,ts,ts,&player);
}

void TestScene::SetEnemies(std::string scene_name)
{
    std::vector<int> bats = sceneConfig.getBats(scene_name);
    std::vector<int> zombies = sceneConfig.getZombies(scene_name);

    size_t l=0;
    while (bats.size()>l)
    {
        contener.Register(new EnemyBat(bats.at(l),bats.at(l+1),&player));
        l+=2;
    }
    l=0;
    while (zombies.size()>l)
    {
        contener.Register(new EnemyZombie(zombies.at(l),zombies.at(l+1),zombies.at(l+2),&player));
        l+=3;
    }
    //contener.Register(new EnemyBat(500,400,&player));
    //contener.Register(new EnemyZombie(300,490,400,&player));
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

void TestScene::GoNextScene()
{
    manager->LoadScene(1);
}
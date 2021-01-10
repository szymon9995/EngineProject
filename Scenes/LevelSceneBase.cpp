#include "LevelSceneBase.h"
#include"../Engine/StartUpConfig.h"

LevelSceneBase::LevelSceneBase(SceneManager* manager)
{
    this->manager=manager;
}

LevelSceneBase::~LevelSceneBase()
{
     OnDestroy();
}

void LevelSceneBase::Draw()
{
    camera.UpdateCameraForeground();
    contener.Draw();
    player.draw();
    exitTile->draw();
    camera.UpdateCameraBackround();
    hpBar.draw();

    if(player.getHp()==0)
        AlDrawable::drawText(font,RED,StartUpConfig::getDisplayWidth()/2,StartUpConfig::getDisplayHeight()/2,"You Died! To Continue Press Y");
}

void LevelSceneBase::Update()
{

    player.update();
    exitTile->update();
    hpBar.update();

    contener.Update();

    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_ESCAPE))
        manager->stopApp();

    if(exitTile->isNextLevel())
        GoNextScene();

    if(player.getHp()==0)
    {
        if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_Y))
            this->OnLoad();
    }

}
void LevelSceneBase::OnDestroy()
{
    contener.Unload();
}

void LevelSceneBase::OnCreate()
{
    scene_name = "test";
    SetPlayer(scene_name);
    SetUI(scene_name);
    CreateTiles(scene_name);
    SetEnemies(scene_name);
    SetCamera();
}

void LevelSceneBase::CreateTiles(std::string scene_name)
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
            contener.Register(Tile::getTile(i*ts,j*ts,ts,ts,&player,&camera,x));
        i++;
    }

    int x=sceneConfig.getExitX(scene_name);
    int y=sceneConfig.getExitY(scene_name);

    exitTile = new DoorTile(x,y,ts,ts,&player,&camera);
}

void LevelSceneBase::SetEnemies(std::string scene_name)
{
    std::vector<int> bats = sceneConfig.getBats(scene_name);
    std::vector<int> zombies = sceneConfig.getZombies(scene_name);
    int ts = sceneConfig.getTileSize();
    size_t l=0;
    while (bats.size()>l)
    {
        contener.Register(new EnemyBat(bats.at(l),bats.at(l+1),ts/2,ts/2,&player));
        l+=2;
    }
    l=0;
    while (zombies.size()>l)
    {
        contener.Register(new EnemyZombie(zombies.at(l),zombies.at(l+1),zombies.at(l+2),ts,ts,&player));
        l+=3;
    }
    //contener.Register(new EnemyBat(500,400,&player));
    //contener.Register(new EnemyZombie(300,490,400,&player));
}

void LevelSceneBase::SetPlayer(std::string scene_name)
{
    int x=sceneConfig.getPlayerX(scene_name);
    int y=sceneConfig.getPlayerY(scene_name);
    int s = sceneConfig.getTileSize();
    player.LoadPlayer(x,y,s,s);
}

void LevelSceneBase::SetUI(std::string scene_name)
{
    //contener.Register(new HpBar(50,50,&player));
    int x = sceneConfig.getHpBarX();
    int y = sceneConfig.getHpBarY();
    hpBar.setVar(x,y,&player);

    font.LoadFont("fonts/comic.ttf",40,0);
}

void LevelSceneBase::OnLoad()
{
    std::cout<<"Loaded";
    if(SaveConfig::shouldLoad())
    {
        std::cout<<"SaveLoad";
        int x = SaveConfig::getPlayerX();
        int y = SaveConfig::getPlayerY();
        int s = sceneConfig.getTileSize();
        player.LoadPlayer(x,y,s,s);
        contener.ResurectAllEntities();
    }
    else
    {
        SaveProgress();
        std::cout<<"ProgressSaved"<<std::endl;

    }
    ///////////pozniej na gore
    SetPlayer(scene_name);
    //////////
    exitTile->reloadDoor();
}

void LevelSceneBase::SetCamera()
{
    camera.setCameraScreenSize(StartUpConfig::getDisplayWidth(),StartUpConfig::getDisplayHeight());
    camera.setCameraToPlayer(&player);
}
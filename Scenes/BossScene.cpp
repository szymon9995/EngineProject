#include "BossScene.h"

void BossScene::Draw()
{
    LevelSceneBase::Draw();
    camera.UpdateCameraForeground();
    boss->draw();
    if(boss->getHp()!=0)
    {
        for(int i=0;i<3;i++)
            blockade[i]->draw();
    }
    camera.UpdateCameraBackround();
    AlDrawable::drawText(font,RED,StartUpConfig::getDisplayWidth()-200,30,"Boos:%d",boss->getHp());
}

void BossScene::Update()
{
    LevelSceneBase::Update();
    boss->update();
    if(boss->getHp()!=0)
    {
        for(int i=0;i<3;i++)
            blockade[i]->update();
    }
}

void BossScene::OnCreate()
{
    scene_name = "boss";
    SetPlayer(scene_name);
    SetUI(scene_name);
    CreateTiles(scene_name);
    SetEnemies(scene_name);   
    SetCamera();

    boss = new EnemyBoss(1300,200,100,100,&player);
    boss->setRML(1300,350,850,500,400,350);
    //contener.Register(new EnemyBoss(1300,200,100,100,&player));
    int ts = sceneConfig.getTileSize();
    for(int i=0;i<3;i++)
    {
        blockade[i] = new Tile(1350,500+(i*ts),ts,ts,13,&player,&camera);
    }
}

void BossScene::GoNextScene()
{
    manager->LoadScene(0);
}

void BossScene::SaveProgress()
{
    SaveConfig::saveProgress(3,sceneConfig.getPlayerX("boss"),sceneConfig.getPlayerY("boss"));

    std::cout<<"Saving"<<std::endl;
    std::cout<<"Scene:"<<SaveConfig::getScene()<<std::endl;
    std::cout<<"PlayerX:"<<SaveConfig::getPlayerX()<<std::endl;
    std::cout<<"PlayerY:"<<SaveConfig::getPlayerY()<<std::endl;
}

void BossScene::OnLoad()
{
    LevelSceneBase::OnLoad();
    boss->setHpDefault();
}
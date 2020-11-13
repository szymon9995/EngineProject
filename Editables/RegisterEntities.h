#include "../Engine/EntityContener.h"

#include "../AlAbstract/Entity.h"
#include "../Enitites/Player/Player.h"
#include "../Enitites/Enemies/EnemyTest.h"
#include "../Enitites/Tiles/GrassTile.h"
#include "../Test/Test2.h"

void RegisterEntities(EntityContener &cont)
{
    for(int i=0;i<16;i++)
        for(int j=0;j<14;j++)
            cont.Register(new GrassTile(50*i,50*j,50,50,1,false));

    cont.Register(new Player(50,50,100,100,1,1,5,1));
    cont.Register(new EnemyTest(200,200,50,50,5));
    cont.Register(new Test2());
}
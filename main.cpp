#include "Engine/Engine.h"
#include "AlClasses/AlInitAll.h"

int main()
{

    Engine* engine = Engine::getEngine();
    engine->Start();
    engine->destroyEngine();

    return 0;
}

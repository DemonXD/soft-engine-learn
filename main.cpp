#include "Engine.h"

int main()
{
    Engine::GetInstance()->Init();
    while(Engine::GetInstance()->IsRunning())
    {
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
    }
    Engine::GetInstance()->Clean();
    Engine::GetInstance()->Quit();
    return 0;
}

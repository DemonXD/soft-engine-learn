#include "Engine.h"

Engine* Engine::s_Instance = nullptr;


bool Engine::Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }
    m_pWindow = SDL_CreateWindow("Soft Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (m_pWindow == nullptr)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_pRenderer == nullptr)
    {
        SDL_Log("Failed to create Renderer: %s", SDL_GetError());
        return false;
    }
    return m_isRunning = true;
}

bool Engine::Clean()
{
    SDL_RenderClear(m_pRenderer);
    return true;
}

void Engine::Quit()
{
    Clean();
    m_isRunning = false;
    SDL_Quit();
}

void Engine::Update()
{
    SDL_Log("wooo~~~~");
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(m_pRenderer, 124, 218, 254, 255);
    SDL_RenderPresent(m_pRenderer);
}

void Engine::Events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        Quit();
        break;
    default:
        break;
    }
}

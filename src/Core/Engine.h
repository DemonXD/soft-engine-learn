#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine {
    public:
        static Engine* GetInstance(){
            return s_Instance = (s_Instance != nullptr)?s_Instance:new Engine();
        }

        bool Init();
        bool Clean();
        void Quit();

        void Update();
        void Render();
        void Events();

        inline bool IsRunning(){return m_isRunning;}
        inline SDL_Renderer* GetRenderer(){return m_pRenderer;}

    private:
        Engine(){}
        bool m_isRunning;
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
        static Engine* s_Instance;
};

#endif // ENGINE_H

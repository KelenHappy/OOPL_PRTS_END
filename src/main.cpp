#include "App.hpp"
#include "Core/Context.hpp"

#include <SDL.h>
#include <SDL_mixer.h>
#include "Util/Logger.hpp"

bool InitAudio() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        LOG_DEBUG("SDL_Init failed: {}", SDL_GetError());
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        LOG_DEBUG("Mix_OpenAudio failed: {}", Mix_GetError());
        return false;
    }

    int flags = MIX_INIT_MP3;
    if ((Mix_Init(flags) & flags) != flags) {
        LOG_DEBUG("Mix_Init failed: {}", Mix_GetError());
        return false;
    }

    return true;
}

int main(int, char**) {
    if (!InitAudio()) {
        std::cerr << "Audio initialization failed. Exiting." << std::endl;
        return 1;
    }

    auto context = Core::Context::GetInstance();
    App app;

    while (!context->GetExit()) {
        switch (app.GetCurrentState()) {
            case App::State::START:
                app.Start();
                break;

            case App::State::UPDATE:
                app.Update();
                break;

            case App::State::END:
                app.End();
                context->SetExit(true);
                break;
        }
        context->Update();
    }

    Mix_CloseAudio();
    Mix_Quit();
    SDL_QuitSubSystem(SDL_INIT_AUDIO); // 或 SDL_Quit() 若你沒用其他子系統

    return 0;
}

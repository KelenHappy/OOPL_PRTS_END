#pragma once
#include <SDL.h>
#include <string>

class WebMPlayer {
public:
    WebMPlayer();
    ~WebMPlayer();

    bool Load(const std::string& filePath); //
    void Update(float deltaTime); //
    void Render(SDL_Renderer* renderer); //
    void Play(); //
    void Pause(); //
    void Stop(); //

private:
    struct Impl;
    Impl* m_impl; //
};
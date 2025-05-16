#ifndef VIDEO_WEBMPLAYER_HPP
#define VIDEO_WEBMPLAYER_HPP

#include <string>
#include <SDL.h>

class WebMPlayer {
public:
    WebMPlayer();
    ~WebMPlayer();

    bool Load(const std::string& filePath);
    void Play();
    void Pause();
    void Stop();
    void Update();              // 新增Update()
    void Render(SDL_Renderer* renderer);

private:
    struct Impl;
    Impl* m_impl;
};

#endif

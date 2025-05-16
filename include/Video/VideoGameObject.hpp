#ifndef UTIL_VIDEOGAMEOBJECT_HPP
#define UTIL_VIDEOGAMEOBJECT_HPP

#include "Util/GameObject.hpp"
#include "Video/WebMPlayer.hpp"
#include <memory>
#include <string>
#include <SDL.h>

namespace Util {

    class VideoGameObject : public GameObject {
    public:
        VideoGameObject();
        ~VideoGameObject() override;

        bool LoadVideo(const std::string& filepath);

        // 這裡覆寫Draw()時不帶renderer，保留給Drawable繪圖用
        void Draw();

        // 新增：用SDL_Renderer播放影片，這是VideoGameObject特有的功能
        void RenderVideo(SDL_Renderer* renderer);

        void Play() {
            m_player->Play();
        }
        void Stop() {
            m_player->Pause();
        }
        void Update() {
            if (m_player) {
                m_player->Update();
            }
        }
        void OnRender(SDL_Renderer* renderer) {
            RenderVideo(renderer); // 呼叫 SDL 影片繪製
        }
    private:
        std::unique_ptr<WebMPlayer> m_player;
    };

} // namespace Util

#endif

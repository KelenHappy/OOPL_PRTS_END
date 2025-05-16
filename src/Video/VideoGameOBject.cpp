#include "Video/VideoGameObject.hpp"

namespace Util {

    VideoGameObject::VideoGameObject()
        : GameObject(), m_player(std::make_unique<WebMPlayer>()) {}

    VideoGameObject::~VideoGameObject() = default;

    bool VideoGameObject::LoadVideo(const std::string& filepath) {
        return m_player->Load(filepath);
    }

    void VideoGameObject::Draw(){
        // 照舊調用 GameObject 原本的 Drawable 繪圖行為
        GameObject::Draw();
    }

    void VideoGameObject::RenderVideo(SDL_Renderer* renderer) {
        if(m_player) {
            m_player->Render(renderer);
        }
    }

} // namespace Util

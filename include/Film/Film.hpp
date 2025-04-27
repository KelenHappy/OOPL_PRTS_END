#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"

#ifndef FILM_HPP
#define FILM_HPP

class Film : public Util::GameObject {  // 使用 public 繼承
public:
    Film() = default;

    Film(std::string ff) {
        // 假設 RESOURCE_DIR 是有效的並已正確定義
        FilmImage.emplace_back(RESOURCE_DIR"/Film/" + ff + ".png");

        // 假設 Util::Animation 類別有這樣的構造函數
        this->m_Drawable = std::make_shared<Util::Animation>(FilmImage, false, 40, false, 40);
    }

    ~Film() = default;

    void setsize(float x, float y) {
        m_Transform.scale = {x, y};  // 假設 m_Transform.scale 是有效的
    }

private:
    int timers = 0;
    int lifeTimes = 0;
    std::vector<std::string> FilmImage;
};

#endif // FILM_HPP


#ifndef HPBAR_HPP
#define HPBAR_HPP
#include "Util/GameObject.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"
class HpBar : public Util::GameObject {
public:
    /*
    HpBar() : GameObject(
        std::make_unique<Util::Text>(
            RESOURCE_DIR"/Font/NSTCB.ttf",
            10,
            std::string(20, 'I'),  // 初始化為20個'I'
            Util::Color::FromName(Util::Colors::GREEN_YELLOW)),
        60) {
        SetVisible(false);
    }*/
    HpBar() {
        m_Drawable = std::make_shared<Util::Image>(RESOURCE_DIR"/UI/Hp.png");
        SetVisible(false);
    }
/*
    void Update(float currentHP, float maxHP) {
        if (maxHP <= 0) return;  // 避免除以零
        std::shared_ptr<Util::Text> text = std::dynamic_pointer_cast<Util::Text>(m_Drawable);
        if (text) {
            // 計算當前HP比例對應的'l'數量 (0到20)
            int filledCount = static_cast<int>(std::round((currentHP / maxHP) * 20));
            filledCount = std::clamp(filledCount, 0, 20);  // 確保在0-20範圍內

            // 創建新的字符串：filledCount個'I' + (20-filledCount)個空格
            std::string newText(filledCount, 'I');
            newText.append((20 - filledCount), '.');
            text->SetText(newText);
            // 可選：根據HP比例改變顏色
            if (currentHP < maxHP * 0.3) {
                text->SetColor(Util::Color::FromName(Util::Colors::RED));
            } else if (currentHP < maxHP * 0.6) {
                text->SetColor(Util::Color::FromName(Util::Colors::YELLOW));
            } else {
                text->SetColor(Util::Color::FromName(Util::Colors::GREEN_YELLOW));
            }
        }
    }*/
    void Update(float currentHP, float maxHP) {
        glm::vec2 nowp=m_Transform.scale;
        m_Transform.scale.x=std::max(std::min( currentHP/maxHP,1.0f),0.0f)*0.8f;
        m_Transform.translation.x-=(nowp.x-m_Transform.scale.x)*40;
    }
    void SetTransform(glm::vec2 transform) {
        m_Transform.translation=transform+glm::vec2{m_Transform.scale.x*40-40,0};
    }
};

#endif //HPBAR_HPP

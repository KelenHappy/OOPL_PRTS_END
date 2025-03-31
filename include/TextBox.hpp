//
// Created by AaronChiu on 2025/3/13.
//
#include "Util/GameObject.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"
#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP
class TextBox:public Util::GameObject{
public:
    TextBox(int size) : GameObject(
            std::make_unique<Util::Text>(RESOURCE_DIR"/Font/SWM.ttf",
                size,
                "                               ",
                Util::Color::FromName(Util::Colors::WHITE)),
            100) {
        m_Transform.translation = {50.0F, 50.0F};
    }
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    void SetText(const std::string& Phase) {
        auto temp = std::dynamic_pointer_cast<Util::Text>(m_Drawable);
        temp->SetText(Phase);
    }

    void SetColor(const std::string& Phase) {
        auto temp = std::dynamic_pointer_cast<Util::Text>(m_Drawable);
        temp->SetColor(Util::Color::FromName(Util::Colors::YELLOW));
    }

};

#endif //TEXTBOX_HPP

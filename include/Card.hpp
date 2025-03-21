//
// Created by AaronChiu on 2025/3/21.
//

#ifndef CARD_HPP
#define CARD_HPP
#include "AnimatedCharacter.hpp"
#include "ClassState.hpp"
#include "ImgItem.hpp"
#include "TextBox.hpp"
#include "Util/GameObject.hpp"

class Card:Util::GameObject {
    public:
    Card(ClassState classState);
    private:
    void createclass(ClassState cs);
    std::shared_ptr<ImgItem>m_class;
    std::shared_ptr<TextBox> m_cost;
    int cost;
    //std::shared_ptr<AnimatedCharacter> m_Character;
    ClassState m_classState;

};
#endif //CARD_HPP

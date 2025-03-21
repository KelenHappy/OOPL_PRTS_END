//
// Created by AaronChiu on 2025/3/21.
//

#include "Card.hpp"
Card::Card(ClassState classState) {
    this->m_classState = classState;
}
void Card::createclass(ClassState cs) {
    switch (cs) {
        case ClassState::Vanguard:
            m_class = std::make_shared<ImgItem>("/Character/classimg/Vanguard.png");
        break;
        case ClassState::Guard:
            m_class = std::make_shared<ImgItem>("/Character/classimg/Guard.png");
        break;
        case ClassState::Sniper:
            m_class = std::make_shared<ImgItem>("/Character/classimg/Sniper.png");
        break;
        case ClassState::Defender:
            m_class = std::make_shared<ImgItem>("/Character/classimg/Defender.png");
        break;
        case ClassState::Medic:
            m_class = std::make_shared<ImgItem>("/Character/classimg/Medic.png");
        break;
        case ClassState::Supporter:
            m_class = std::make_shared<ImgItem>("/Character/classimg/Supporter.png");
        break;
        case ClassState::Caster:
            m_class = std::make_shared<ImgItem>("/Character/classimg/Caster.png");
        break;
        case ClassState::Specialist:
            m_class = std::make_shared<ImgItem>("/Character/classimg/Specialist.png");
        break;
        default:
                m_class = std::make_shared<ImgItem>("/Character/classimg/Specialist.png");
        break;
    }
}


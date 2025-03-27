//
// Created by AaronChiu on 2025/3/21.
//

#include "Card.hpp"
Card::Card(ClassState classState,int cost) {
    m_Drawable = std::make_shared<Util::Image>(RESOURCE_DIR"/Character/Vanguard/Texas/Default/1.png");
    SetZIndex(27);
    cardsize=0.8f;
    m_cost= std::make_shared<TextBox>(20);
    m_Cardback=std::make_shared<ImgItem>("/Maps/CardBack.png");
    m_Cardback->setsize(0.7,0.7);
    m_Cardback->SetZIndex(26);
    this->m_classState = classState;
    this->cost = cost;
    createclass(classState);
    createinfo();
    SetCardSize(cardsize);
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
    m_class->setsize(0.15,0.15);
    m_class->SetZIndex(28);
}
void Card::createinfo() {
    m_cost->SetText(std::to_string(cost));
}
void Card::SetTranform(float x, float y) {
    m_Transform.translation.x = x;
    m_Transform.translation.y = y;
    m_Cardback->m_Transform.translation.x = x;
    m_Cardback->m_Transform.translation.y = y;
    m_cost->m_Transform.translation.x = x+30*cardsize;
    m_cost->m_Transform.translation.y = y+67*cardsize;
    m_class->m_Transform.translation.x = x;
    m_class->m_Transform.translation.y = y+71*cardsize;

}
void Card::SetCardSize(float size) {
    m_class->setsize(static_cast<float>(0.15*size),static_cast<float>(0.15 * size));
    m_Cardback->setsize(static_cast<float>(0.7*size),static_cast<float>(0.7 * size));
    m_Transform.scale={size,size };

}





//
// Created by AaronChiu on 2025/3/21.
//

#include "Card.hpp"
Card::Card(std::shared_ptr<AnimatedCharacter> Character) {
    this->m_Character=Character;
    m_Drawable = std::make_shared<Util::Image>(RESOURCE_DIR"/Character/"+Character->GetJob()+"/"+Character->GetCharacterName()+"/Default/1.png");
    SetZIndex(27);
    cardsize=0.6f;
    m_cost= std::make_shared<TextBox>(20);
    m_cost->SetZIndex(34);
    m_DeadTime= std::make_shared<TextBox>(30);
    m_DeadTime->SetZIndex(34);
    m_Cardback=std::make_shared<ImgItem>("/Maps/CardBack.png");
    m_Cardback->setsize(0.7,0.7);
    m_Cardback->SetZIndex(26);
    this->m_classState =m_Character->GetJobClass();
    this->cost =m_Character->GetSetCost();
    createclass(m_classState);
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
    m_Transform.translation={x,y};
    m_Cardback->m_Transform.translation={x,y};
    m_cost->m_Transform.translation.x = x+(30*cardsize);
    m_cost->m_Transform.translation.y = y+(67*cardsize);
    m_class->m_Transform.translation.x = x;
    m_class->m_Transform.translation.y = y+(71*cardsize);
    m_DeadTime->m_Transform.translation={x,y};
}
void Card::SetCardSize(float size) {
    m_class->setsize(static_cast<float>(0.15*size),static_cast<float>(0.15 * size));
    m_Cardback->setsize(static_cast<float>(0.7*size),static_cast<float>(0.7 * size));
    m_Transform.scale={size,size };

}
void Card::UpdateCard() {
    m_cost->SetText(std::to_string(m_Character->GetPlaceCostNum()));
    if(m_Character->GetVisibility()) {
        setAllVisible(false);
    }
    else if(m_Character->GetDie()) {
        setAllVisible(true);
        m_Cardback->SetNewIMGstd("/Film/die.png");
        m_Cardback->setsize(static_cast<float>(1.05*m_Transform.scale.x),static_cast<float>(1.05 *m_Transform.scale.x));
        m_Cardback->SetZIndex(30);
    }
    else {
        setAllVisible(true);
        m_DeadTime->SetVisible(false);
        m_Cardback->SetNewIMGstd("/Maps/CardBack.png");
        m_Cardback->setsize(static_cast<float>(0.7*m_Transform.scale.x),static_cast<float>(0.7 * m_Transform.scale.x));
        m_Cardback->SetZIndex(26);
    }

}
void Card::UpdateCardS() {
    m_cost->SetText(std::to_string(m_Character->GetPlaceCostNum()));
    if(m_Character->GetDie()) {
        m_Character->DeDieCost(1);
        if(m_Character->GetDieCost()<=0) {
            m_Character->SetDead(false);
            m_DeadTime->SetVisible(false);
            UpdateCard();
        }
        m_DeadTime->SetText(std::to_string(m_Character->GetDieCost()));
    }
}


void Card::setAllVisible(bool visible) {
    m_class->SetVisible(visible);
    m_Cardback->SetVisible(visible);
    m_cost->SetVisible(visible);
    m_DeadTime->SetVisible(visible);
    SetVisible(visible);
}




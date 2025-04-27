#include "Card/HalfCard.hpp"
HalfCard::HalfCard(std::shared_ptr<AnimatedCharacter> Character) {
    this->m_Character=Character;
    choseindex=-1;
    m_Drawable = std::make_shared<Util::Image>(RESOURCE_DIR"/HalfCard/"+Character->GetJob()+"/"+Character->GetCharacterName()+".png");
    SetZIndex(27);
    cardsize=1.0f;
    m_cost= std::make_shared<TextBox>(25);
    m_cost->SetColor(Util::Colors::DODGER_BLUE);
    m_name= std::make_shared<TextBox>(15);
    m_name->SetText(Character->GetChineseName());
    m_name->SetZIndex(29);
    m_Cardback=std::make_shared<ImgItem>("/HalfCard/cardbackgraund.png");
    m_Cardback->SetZIndex(26);
    m_Cardback2=std::make_shared<ImgItem>("/HalfCard/cardb2.png");
    m_Cardback2->SetZIndex(28);
    m_choicebar=std::make_shared<ImgItem>("/HalfCard/choicebar.png");
    m_choicebar->SetZIndex(31);
    m_choicebar->SetVisible(false);
    this->m_classState =m_Character->GetJobClass();
    createclass(m_classState);
    SetCardSize(cardsize);
    Update();
    SetTranform(0,0);
}
void HalfCard::Setchoseindex(int index) {
    choseindex=index;
    Update();
}

void HalfCard::createclass(ClassState cs) {
    switch (cs) {
        case ClassState::Vanguard:
            m_class = std::make_shared<ImgItem>("/HalfCard/class/Vanguard.png");
        break;
        case ClassState::Guard:
            m_class = std::make_shared<ImgItem>("/HalfCard/class/Guard.png");
        break;
        case ClassState::Sniper:
            m_class = std::make_shared<ImgItem>("/HalfCard/class/Sniper.png");
        break;
        case ClassState::Defender:
            m_class = std::make_shared<ImgItem>("/HalfCard/class/Defender.png");
        break;
        case ClassState::Medic:
            m_class = std::make_shared<ImgItem>("/HalfCard/class/Medic.png");
        break;
        case ClassState::Supporter:
            m_class = std::make_shared<ImgItem>("/HalfCard/class/Supporter.png");
        break;
        case ClassState::Caster:
            m_class = std::make_shared<ImgItem>("/HalfCard/class/Caster.png");
        break;
        case ClassState::Specialist:
            m_class = std::make_shared<ImgItem>("/HalfCard/class/Specialist.png");
        break;
        default:
            m_class = std::make_shared<ImgItem>("/HalfCard/class/Specialist.png");
        break;
    }
    m_class->SetZIndex(29);
}
void HalfCard::createinfo() {
    m_name->SetText(m_Character->GetChineseName());
}
void HalfCard::SetTranform(float x, float y) {
    m_Transform.translation.x = x;
    m_Transform.translation.y = y;
    m_name->m_Transform.translation=glm::vec2{x+20,y-85};
    m_cost->m_Transform.translation=glm::vec2{x+40,y+80};
    m_Cardback2->m_Transform.translation=glm::vec2{x,y-86};
    m_Cardback->m_Transform.translation.x = x;
    m_Cardback->m_Transform.translation.y = y;
    m_class->m_Transform.translation.x = x-35*cardsize;
    m_class->m_Transform.translation.y = y-85*cardsize;

}
void HalfCard::SetCardSize(float size) {
    m_class->setsize(static_cast<float>(size),static_cast<float>(size));
    m_Cardback->setsize(static_cast<float>(size),static_cast<float>(size));
    m_Transform.scale={size,size };

}
void HalfCard::Update() {
    m_name->SetText(m_Character->GetChineseName());
    if (choseindex!=-1) {
        m_cost->SetText(std::to_string(choseindex));
        m_cost->SetVisible(true);
        m_choicebar->SetVisible(true);
    }
    else {
        m_cost->SetVisible(false);
        m_choicebar->SetVisible(false);
    }

}






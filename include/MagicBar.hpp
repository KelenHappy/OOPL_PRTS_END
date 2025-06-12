
#ifndef MAGICBAR_HPP
#define MAGICBAR_HPP
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class MagicBar: public Util::GameObject {
    public:
    MagicBar() {
        m_Drawable = std::make_shared<Util::Image>(RESOURCE_DIR"/UI/Mana.png");
        SetVisible(false);
        SetZIndex(60);
    }
    void Update(float currentHP, float maxHP,bool skillIsOpen) {
        if(skillIsOpen) {
            auto imagePtr = std::static_pointer_cast<Util::Image>(m_Drawable);
            imagePtr->SetImage(RESOURCE_DIR"/UI/skillopen.png");
            m_Transform.scale.y=0.5f;
            glm::vec2 nowp=m_Transform.scale;
            m_Transform.scale.x=0.8f;
            m_Transform.translation.x-=(nowp.x-m_Transform.scale.x)*40;
        }
        else if(maxHP==-1) {
            auto imagePtr = std::static_pointer_cast<Util::Image>(m_Drawable);
            imagePtr->SetImage(RESOURCE_DIR"/UI/HpBack.png");
            m_Transform.scale.y=0.5f;
            glm::vec2 nowp=m_Transform.scale;
            m_Transform.scale.x=0.8f;
            m_Transform.translation.x-=(nowp.x-m_Transform.scale.x)*40;

        }
        else {
            auto imagePtr = std::static_pointer_cast<Util::Image>(m_Drawable);
            imagePtr->SetImage(RESOURCE_DIR"/UI/Mana.png");
            glm::vec2 nowp=m_Transform.scale;
            m_Transform.scale.y=1.0f;
            m_Transform.scale.x=std::max(std::min( currentHP/maxHP,1.0f),0.0f)*0.8f;
            m_Transform.translation.x-=(nowp.x-m_Transform.scale.x)*40;
        }

    }
    void SetTransform(glm::vec2 transform) {
        m_Transform.translation=transform+glm::vec2{m_Transform.scale.x*40-40,0};
    }
};
#endif //MAGICBAR_HPP

//
// Created by AaronChiu on 2025/6/10.
//

#ifndef HPBARUI_HPP
#define HPBARUI_HPP
#include "../ImgItem.hpp"
#include "../../PTSD/include/Util/GameObject.hpp"
#include "../../PTSD/include/Util/Text.hpp"
#include "../../PTSD/include/Util/Color.hpp"
#include "../../PTSD/include/Util/Image.hpp"

class HpBarUI : public Util::GameObject {
public:
    HpBarUI() {
        HpBar=  std::make_shared<ImgItem>("/Maps/Hp.png");
        HpBack= std::make_shared<ImgItem>("/Maps/HpBack.png");
        ManaBar= std::make_shared<ImgItem>("/Maps/Mana.png");
        for (auto& obj : {HpBack,HpBar,ManaBar}) {
            obj->SetVisible(false);
            obj->SetZIndex(60);
        }
        HpBack->SetZIndex(59);
    }
    void Update(float nowHP, float maxHP,float nowMana,float maxMana) {
        HpBar->m_Transform.scale={nowHp/maxHP,1.0f};
        ManaBar->m_Transform.scale={nowMana/maxMana,1.0f};
        HpBar->m_Transform.translation={m_Transform.translation.x-(HpBar->m_Transform.scale)*50,y};
        ManaBar->m_Transform.translation={m_Transform.translation.x-(HpBar->m_Transform.scale)*50,y};
    }
    void SetPostion(float x,float y) {
        m_Transform.translation={x,y};
        HpBack->m_Transform.translation={x,y};
        HpBar->m_Transform.translation={x-(HpBar->m_Transform.scale)*50,y};
        ManaBar->m_Transform.translation={x-(HpBar->m_Transform.scale)*50,y};
    }

private:
    std::shared_ptr<ImgItem> HpBar;
    std::shared_ptr<ImgItem> HpBack;
    std::shared_ptr<ImgItem> ManaBar;



};

#endif //HPBARUI_HPP

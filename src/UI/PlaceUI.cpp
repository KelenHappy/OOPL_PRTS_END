#include <iostream>

#include "UI/PlaceUI.hpp"
Direction PlaceUI::NewDirection(const glm::vec2& position) {
    glm::vec2 delta = position - m_Transform.translation;
    float deadZone = 25.0f;
    m_Gan->m_Transform.translation=ClampToDiamond(position);

    // 檢查是否在死區內
    if (length(delta) < deadZone) {
        return Direction::CENTER;
    }

    // 計算角度
    float angle = glm::degrees(atan2(delta.y, delta.x)); // 角度範圍：[-180, 180]

    // 正規化角度到 [-180, 180]
    if (angle > 180.0f) angle -= 360.0f;
    if (angle <= -180.0f) angle += 360.0f;

    // 根據角度分區判斷方向（上下左右）
    if (angle >= -45 && angle <= 45) {
        return Direction::EAST;
    } else if (angle > 45 && angle < 135) {
        return Direction::SOUTH;
    } else if (angle >= 135 || angle <= -135) {
        return Direction::WEST;
    } else {
        return Direction::NORTH;
    }
}
void PlaceUI::setnewcharacterskill(std::shared_ptr<AnimatedCharacter> Character) {
    m_skill ->SetNewIMGstd("/Character/"+Character->GetJob()+"/"+Character->GetCharacterName()+"/Default/s.png");
}
void PlaceUI::openUI(int a) {
    m_Diamond->SetVisible(true);
    switch (a) {
        case 0:
            m_Gan->SetVisible(true);
            m_back->SetVisible(true);
            break;
        case 1:
            m_skill->SetVisible(true);
            m_back->SetVisible(true);
            m_skillBack->SetVisible(true);
            m_skillText->SetVisible(true);
            break;
        default:
            break;
    }

}
void PlaceUI::closeUI() {
    for (auto& obj : {m_Diamond, m_back, m_Gan, m_skill,m_skillBack}) {
        obj->SetVisible(false);
    }
    m_skillText->SetVisible(false);
}
void PlaceUI::UpdateUI(std::shared_ptr<AnimatedCharacter> Character) {
    int n=Character->GetSkillNow();
    int c=Character->GetSkillCost();
   m_skillText->SetText(std::to_string(n)+"/"+std::to_string(c));
    if(c==-1) {
        m_skillText->SetText("-/-");
        m_skillBack->SetNewIMGstd("/UI/skill.png");
    }
    else if(n>=c) {
        m_skillBack->SetNewIMGstd("/UI/ready.png");
        m_skillText->SetVisible(false);
    }
    else {
        m_skillBack->SetNewIMGstd("/UI/skill.png");
    }
}




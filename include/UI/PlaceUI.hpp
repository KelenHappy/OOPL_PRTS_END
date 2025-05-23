
#ifndef PLACEUI_HPP
#define PLACEUI_HPP
#include "ImgItem.hpp"
#include "Character/AnimatedCharacter.hpp"
#include "Enumclass/Direction.hpp"

class PlaceUI:public Util::GameObject {
public:
    PlaceUI() {
        SetZIndex(40);
        m_Gan=std::make_shared<ImgItem>("/Maps/UIC.png");
        m_back=std::make_shared<ImgItem>("/Maps/X.png");
        m_skill=std::make_shared<ImgItem>("/Character/Vanguard/Texas/Default/s.png");
        m_Diamond=std::make_shared<ImgItem>("/Maps/UIDiamond.png");
        for (auto& obj : {m_Diamond, m_back, m_Gan, m_skill}) {
            obj->SetVisible(false);
            obj->m_Transform.scale={0.8,0.8};
        }
        m_back->m_Transform.scale={0.7,0.7};
        m_Diamond->SetZIndex(50);
        m_back->SetZIndex(49);
        m_Gan->SetZIndex(51);
        m_skill->SetZIndex(52);
        SetPostion(0,0);
    }
    std::vector<std::shared_ptr<Util::GameObject>> GetChildren() {
        std::vector<std::shared_ptr<Util::GameObject>> children;
        children.push_back(m_Gan);
        children.push_back(m_back);
        children.push_back(m_skill);
        children.push_back(m_Diamond);
        return children;
    }
    void SetPostion(float x,float y) {
        m_Transform.translation={x,y};
        m_Diamond->m_Transform.translation={x,y};
        m_Gan->m_Transform.translation={x,y};
        m_back->m_Transform.translation={x-83,y+80};
        m_skill->m_Transform.translation={x+60,y-60};
    }
    glm::vec2 ClampToDiamond(glm::vec2 pos) {
        glm::vec2 center =m_Transform.translation;
        int radius =80;
        glm::vec2 delta = pos - center;
        float manhattanDist = std::abs(delta.x) + std::abs(delta.y);

        if (manhattanDist <= radius) {
            return pos; // 在菱形範圍內
        }

        float scale = static_cast<float>(radius) / manhattanDist;
        glm::vec2 clampedDelta = glm::round(delta * scale);  // 四捨五入到整數格
        return center + clampedDelta;
    }
    Direction NewDirection(const glm::vec2& position);
    void setnewcharacterskill(std::shared_ptr<AnimatedCharacter> Character);
    void openUI(int a);
    void closeUI();
    std::shared_ptr<ImgItem> Getback(){return m_back;}
    private:
    std::shared_ptr<ImgItem> m_Diamond;
    std::shared_ptr<ImgItem>m_Gan;
    std::shared_ptr<ImgItem>m_back;
    std::shared_ptr<ImgItem>m_skill;


};
#endif //PLACEUI_HPP

//
// Created by AaronChiu on 2025/3/21.
//

#ifndef CARD_HPP
#define CARD_HPP
#include "Character/AnimatedCharacter.hpp"
#include "ClassState.hpp"
#include "ImgItem.hpp"
#include "TextBox.hpp"
#include "Util/GameObject.hpp"

class Card:public Util::GameObject {
    public:
    Card(std::shared_ptr<AnimatedCharacter> Character);
    glm::vec2 GetPosition() const { return m_Transform.translation; }
    std::shared_ptr<ImgItem> Getclass(){return m_class;}
    std::shared_ptr<TextBox> GetCosttext(){return m_cost;}
    std::shared_ptr<ImgItem> GetCardback(){return m_Cardback;}
    std::shared_ptr<AnimatedCharacter> GetCharacter(){return m_Character;}
    std::shared_ptr<TextBox> GetMDeadTime(){return m_DeadTime;}
    void SetCardSize(float size);
    void SetTranform(float x, float y);//設所有Card物件的座標
    void UpdateCard();
    void UpdateCardS();
    void setAllVisible(bool visible);
    private:
    void createinfo();
    void createclass(ClassState cs);
    std::shared_ptr<ImgItem>m_class;
    std::shared_ptr<ImgItem>m_Cardback;
    std::shared_ptr<TextBox> m_cost;
    std::shared_ptr<TextBox> m_DeadTime;
    int cost;
    float cardsize;
    std::shared_ptr<AnimatedCharacter> m_Character;
    ClassState m_classState;

};
#endif //CARD_HPP

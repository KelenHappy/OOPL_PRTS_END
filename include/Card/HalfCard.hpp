#ifndef HALF_CARD_HPP
#define HALF_CARD_HPP
#include "Character/AnimatedCharacter.hpp"
#include "ClassState.hpp"
#include "ImgItem.hpp"
#include "TextBox.hpp"
#include "Util/GameObject.hpp"

class HalfCard:public Util::GameObject {
    public:
    HalfCard(std::shared_ptr<AnimatedCharacter> Character);
    std::shared_ptr<ImgItem> Getclass(){return m_class;}
    std::shared_ptr<TextBox> GetCosttext(){return m_cost;}
    std::shared_ptr<ImgItem> GetCardback(){return m_Cardback;}
    std::shared_ptr<AnimatedCharacter> GetCharacter(){return m_Character;}
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        return {m_class,m_cost,m_Cardback,m_name,m_choicebar,m_Cardback2};
    }
    void SetCardSize(float size);
    void SetTranform(float x, float y);//設所有Card物件的座標
    void Update();
    void Setchoseindex(int index);
    int Getchoseindex(){return choseindex;}


    private:
    void createinfo();
    void createclass(ClassState cs);
    std::shared_ptr<ImgItem>m_class;
    std::shared_ptr<ImgItem>m_Cardback;
    std::shared_ptr<ImgItem>m_Cardback2;
    std::shared_ptr<ImgItem>m_choicebar;
    std::shared_ptr<TextBox> m_name;
    std::shared_ptr<TextBox> m_cost;
    bool choice;
    int choseindex;
    float cardsize;
    std::shared_ptr<AnimatedCharacter> m_Character;
    ClassState m_classState;

};
#endif //HALF_CARD_HPP

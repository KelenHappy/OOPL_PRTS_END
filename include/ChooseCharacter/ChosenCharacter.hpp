#ifndef CHOSEN_CHARACTER_HPP
#define CHOSEN_CHARACTER_HPP
#include "CreateIMG.hpp"
#include "TextBox.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Text.hpp"
#include "Card/HalfCard.hpp"
#include "ImgItem.hpp"

class ChosenCharacter:public Util::GameObject {
    public:
    ChosenCharacter();
    void CreateNewCharacter();
    void CreateHalfCard();
    void Settran();
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {return { m_background,m_Exit,m_Start,m_NowMap};}
    [[nodiscard]]std::vector<std::shared_ptr<HalfCard>> GetHalfCard(){return m_HalfCard;}
    [[nodiscard]]std::shared_ptr<TextBox> GetExit(){return m_Exit;}
    [[nodiscard]]std::shared_ptr<TextBox> GetNowMaps(){return m_NowMap;}
	[[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildrenCard() const {
        std::vector<std::shared_ptr<Util::GameObject>> result;
        for(size_t i=0;i<m_HalfCard.size();i++) {
            result.push_back(m_HalfCard[i]);
            for(size_t j=0;j<m_HalfCard[i]->GetChildren().size();j++) {
                result.push_back(m_HalfCard[i]->GetChildren()[j]);
            }
        }
        return result;
    }
    void ChangeMaps(std::string st) {
        m_NowMap->SetText("現在地圖:"+st);
    }

    std::vector<std::shared_ptr<AnimatedCharacter>> GetTotalCharacter() const {return m_ToTalCharacter;}
    std::vector<std::shared_ptr<AnimatedCharacter>> GetChoiceCharacter() ;
    std::vector<std::shared_ptr<HalfCard>> GetChoiceCard() {return m_ChoiceCard;}
    void AddHalfCard(std::shared_ptr<HalfCard> card) {m_HalfCard.push_back(card);}
    void AddChoiceCharacter(std::shared_ptr<HalfCard> character) {m_ChoiceCard.push_back(character);}
    void RemoveChoiceCharacter(int index) {
        m_ChoiceCard.erase(m_ChoiceCard.begin() + (index - 1));
        UpDateChoiceCharacter();
    }
    void UpDateChoiceCharacter();
    private:
    bool Icreate;
    std::vector<std::shared_ptr<AnimatedCharacter>> m_ToTalCharacter;
    std::vector<std::shared_ptr<HalfCard>> m_ChoiceCard;
	std::vector<std::shared_ptr<HalfCard>> m_HalfCard;
    std::shared_ptr<TextBox> m_Exit;
    std::shared_ptr<TextBox> m_NowMap;
    std::shared_ptr<ImgItem> m_Start;
    std::shared_ptr<CreateIMG> m_background;





};
#endif //MAINSCREAM_HPP

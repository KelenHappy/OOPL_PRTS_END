#ifndef CHOSEN_CHARACTER_HPP
#define CHOSEN_CHARACTER_HPP
#include "CreateIMG.hpp"
#include "TextBox.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Text.hpp"
#include "Card/HalfCard.hpp"

class ChosenCharacter:public Util::GameObject {
    public:
    ChosenCharacter() {
        this->m_background=std::make_shared<CreateIMG>("/HalfCard/CC.png",-10);
    };
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        return { m_background};
    }
	void AddHalfCard(std::shared_ptr<HalfCard> card) {
        m_HalfCard.push_back(card);
    }
	[[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildrenCard() const {
        std::vector<std::shared_ptr<Util::GameObject>> result;
        for(size_t i=0;i<1/*m_HalfCard.size()*/;i++) {
            result.push_back(m_HalfCard[i]);
            for(size_t j=0;j<m_HalfCard[i]->GetChildren().size();j++) {
                result.push_back(m_HalfCard[i]->GetChildren()[j]);
            }
        }
        return result;
    }
    private:
	std::vector<std::shared_ptr<HalfCard>> m_HalfCard;
    std::shared_ptr<TextBox> m_Exit;
    std::shared_ptr<CreateIMG> m_background;





};
#endif //MAINSCREAM_HPP

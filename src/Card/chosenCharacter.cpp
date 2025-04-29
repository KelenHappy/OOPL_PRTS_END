#include "Character/Medic/Sussurro.hpp"
#include "Character/Medic/Ptilopsis.hpp"
#include "Character/Medic/Warfarin.hpp" 

#include "Character/Sniper/Exudiai.hpp"
#include "Character/Sniper/Kroos.hpp"
#include "Character/Sniper/W.hpp"

#include "Character/Vanguard/Ines.hpp"
#include "Character/Vanguard/Myrtle.hpp"
#include "Character/Vanguard/Texas.hpp"
#include "ChooseCharacter/ChosenCharacter.hpp"
#include "Util/Logger.hpp"

ChosenCharacter::ChosenCharacter() {
    this->m_background=std::make_shared<CreateIMG>("/HalfCard/CC.png",-10);
    this->m_Exit= std::make_shared<TextBox>(65);
    m_Exit->SetText("<");
    m_Exit->m_Transform.translation={-595,313};
    Icreate=false;
}
void ChosenCharacter::CreateNewCharacter() {
    if (Icreate) {return;}
    m_ToTalCharacter = {
        std::make_shared<Sussurro>(),
        std::make_shared<Ptilopsis>(),
		std::make_shared<Warfarin>(),
		
		std::make_shared<Exusiai>(),
		std::make_shared<Kroos>(),
		std::make_shared<W>(),
		
        std::make_shared<Texas>(),
        std::make_shared<Ines>(),
        std::make_shared<Myrtle>()
    };
    CreateHalfCard();
    Icreate=true;
}
void ChosenCharacter::CreateHalfCard() {
    if (m_ToTalCharacter.empty()) return;  // 避免空 vector
    for (size_t i = 0; i < m_ToTalCharacter.size(); i++) {
        if (!m_ToTalCharacter[i]) continue;  // 跳過 nullptr

        try {
            std::shared_ptr<HalfCard> cd = std::make_shared<HalfCard>(m_ToTalCharacter[i]);
            m_HalfCard.push_back(cd);
        } catch (const std::exception& e) {
            LOG_ERROR("Failed to create HalfCard: " + std::string(e.what()));
        }
    }
}
void ChosenCharacter::Settran() {
    for (size_t i = 0; i <  m_HalfCard.size(); i++) {
        m_HalfCard[i]->SetTranform(-410+((int(i)%8)*130),225-((int(i)/8)*230));
    }
}
void ChosenCharacter::UpDateChoiceCharacter() {
    for (size_t i = 0; i <  m_ChoiceCard.size(); i++) {
        m_ChoiceCard[i]->Setchoseindex(int(i+1));
    }
}
std::vector<std::shared_ptr<AnimatedCharacter> > ChosenCharacter::GetChoiceCharacter() {
    std::vector<std::shared_ptr<AnimatedCharacter> > result;
    for (size_t i = 0; i <  m_ChoiceCard.size(); i++) {
        result.push_back(m_ChoiceCard[i]->GetCharacter());
    }
    return result;
}





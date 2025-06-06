#include "Character/Medic/Sussurro.hpp"
#include "Character/Medic/Ptilopsis.hpp"
#include "Character/Medic/Warfarin.hpp" 

#include "Character/Sniper/Exudiai.hpp"
#include "Character/Sniper/Kroos.hpp"
#include "Character/Sniper/W.hpp"

#include "Character/Vanguard/Ines.hpp"
#include "Character/Vanguard/Myrtle.hpp"
#include "Character/Vanguard/Texas.hpp"

#include "Character/Guard/Mlynar.hpp"
#include "Character/Guard/SilverAsh.hpp"
#include "Character/Guard/Surtr.hpp"
#include "Character/Guard/Lappland.hpp"

#include "Character/Defender/Cuora.hpp"
#include "Character/Defender/Saria.hpp"
#include "Character/Defender/Horn.hpp"

#include "Character/Caster/Ceobe.hpp"
#include "Character/Caster/Eyja.hpp"
#include "Character/Caster/Ifrit.hpp"

#include "Character/Supporter/Suzuran.hpp"
#include "Character/Supporter/Gnosis.hpp"

#include "Character/Specialist/Mizuki.hpp"
#include "Character/Specialist/Texas_the_Omertosa.hpp"
#include "Character/Specialist/Kirin_R_Yato.hpp"
#include "Character/Specialist/Gravel.hpp"

#include "ChooseCharacter/ChosenCharacter.hpp"
#include "Util/Logger.hpp"

ChosenCharacter::ChosenCharacter() {
    this->m_background=std::make_shared<CreateIMG>("/HalfCard/CC.png",-10);
    this->m_Exit= std::make_shared<TextBox>(65);
    this->m_NowMap= std::make_shared<TextBox>(30);
    this->m_Start=std::make_shared<ImgItem>("/Maps/start.png");
   m_Start->m_Transform.scale={m_Start->m_Transform.scale.x*0.408,m_Start->m_Transform.scale.y*0.4};
    m_Start->m_Transform.translation={500,-235};
    m_Start->SetZIndex(50);
    m_Exit->SetText("<");
    m_NowMap->SetText("現在地圖:主線1-7");
    m_NowMap->SetPosition({395,341});
    m_NowMap->SetColor(Util::Colors::LIGHT_SEA_GREEN);
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
        std::make_shared<Myrtle>(),

        std::make_shared<Mlynar>(),
        std::make_shared<SilverAsh>(),
        std::make_shared<Surtr>(),
        std::make_shared<Lappland>(),

        std::make_shared<Cuora>(),
        std::make_shared<Saria>(),
        std::make_shared<Horn>(),

        std::make_shared<Ceobe>(),
        std::make_shared<Eyja>(),
        std::make_shared<Ifrit>(),

        std::make_shared<Suzuran>(),
        std::make_shared<Gnosis>(),

        std::make_shared<Mizuki>(),
        std::make_shared<TexasTheOmertosa>(),
        std::make_shared<KirinRYato>(),
        std::make_shared<Gravel>()


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
        m_HalfCard[i]->SetTranform(-540+((int(i+1)%9)*130),225-((int(i+1)/9)*230));
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





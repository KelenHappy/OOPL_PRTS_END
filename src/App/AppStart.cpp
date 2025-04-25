#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;
	m_flyUI=std::make_shared<FlyUI>();
	m_0107.AddChild(m_flyUI);
    
	m_MainScream= std::make_shared<MainScream>();
	m_ChosenCharacter = std::make_shared<ChosenCharacter>();
	
	m_TT = std::make_shared<TextBox>(40);
    m_Root.AddChildren(m_MainScream->GetChildren());
	m_map0107=std::make_shared<Map>();
	m_0107.AddChildren(m_map0107->GetChildren());
    gametimer=std::make_shared<GameTimer>();
	m_Hpbar=std::make_shared<HpBar>();
	m_Root.AddChild(m_Hpbar);
	//m_Root.AddChildren();

    // Character
	//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
	/*
	void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
    int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
	defendlevel
	*/
	//Temp
	//角色建立
	m_Sussurro = std::make_shared<Sussurro>();
	m_Warfarin = std::make_shared<Warfarin>();
	m_Ptilopsis = std::make_shared<Ptilopsis>();
	
	m_Exusiai = std::make_shared<Exusiai>();
	m_Kroos = std::make_shared<Kroos>();
	m_W = std::make_shared<W>();

	m_Texas = std::make_shared<Texas>();
	m_Ines = std::make_shared<Ines>();
    m_Myrtle = std::make_shared<Myrtle>();

	// 角色擁有
	m_StartCharacter.push_back(m_Sussurro);
	m_StartCharacter.push_back(m_Exusiai);
	m_StartCharacter.push_back(m_Texas);

	for(size_t i = 0; i < m_StartCharacter.size(); i++){
		std::shared_ptr<HalfCard> cd=std::make_shared<HalfCard>(m_StartCharacter[i]);
		cd->SetTranform(570-(i*144),-300);
		m_ChosenCharacter->AddHalfCard(cd);
		m_HalfCardScreen.AddChildren(m_ChosenCharacter->GetChildrenCard());
		m_HalfCardScreen.AddChild(m_StartCharacter[i]);
	}
}

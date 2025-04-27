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
	// 角色擁有
	m_HalfCardScreen.AddChildren(m_ChosenCharacter->GetChildren());
	m_ChosenCharacter->CreateNewCharacter();
	m_ChosenCharacter->Settran();
	m_HalfCardScreen.AddChildren(m_ChosenCharacter->GetChildrenCard());
}

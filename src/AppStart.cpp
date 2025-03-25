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
    m_MainScream= std::make_shared<MainScream>();
    m_TT = std::make_shared<TextBox>();
    m_Root.AddChildren(m_MainScream->GetChildren());
    m_map0107=std::make_shared<Map>();
    m_0107.AddChildren(m_map0107->GetChildren());
    m_UT=std::make_shared<UseTime>();

    // Character
	//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
	/*
	void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
    int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo
	*/
	m_Sussurro = std::make_shared<Medic>("Sussurro", 119, 61, 60, 61);
	m_Sussurro->SetInfo(70, 18, 2.85, 1345, 488, 122, 0,
	10, 30, 25, "攻擊力+100%，攻擊速度+100同一次作戰中最多使用2次"
	);
	m_Sussurro->SetZIndex(15);
	m_Sussurro->SetState(CharacterState::Default);
	m_Sussurro->SetVisible(false);     
	m_Sussurro->SetLooping(false);

	m_Exudiai = std::make_shared<Sniper>("Exusiai", 240, 61, 60, 60);


	m_Texas = std::make_shared<Vanguard>("Texas", 120, 60, 60, 61);

}

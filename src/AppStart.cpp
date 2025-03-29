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
    int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
	defendlevel
	*/
	//角色建立
	m_Sussurro = std::make_shared<Medic>("Sussurro", 119, 61, 60, 61);
	m_Sussurro->SetInfo(70, 18, 2.85, 1345, -488, 122, 0,
	10, 30, 25, "攻擊力+100%，攻擊速度+100同一次作戰中最多使用2次", "深度治療"
	, 1);
	m_Sussurro->SetZIndex(15);
	m_Sussurro->SetState(CharacterState::Default);
	m_Sussurro->SetVisible(false);     
	m_Sussurro->SetLooping(false);
	//角色技能建立
	
	m_Sussurro->ApplySkillEffects();
	
	m_Exudiai = std::make_shared<Sniper>("Exusiai", 240, 61, 60, 60);
	m_Exudiai->SetInfo(70, 12, 1, 1673, 540, 161, 0,
	20, 30, 15, "攻擊變為5連射，攻擊間隔一定程度縮短(-0.22)，攻擊力提升至110%技能會自動開啟", "過載模式"
	, 1);
	m_Exudiai->SetZIndex(15);
	m_Exudiai->SetState(CharacterState::Default);
	m_Exudiai->SetVisible(false);
	m_Exudiai->SetLooping(false);

	m_Texas = std::make_shared<Vanguard>("Texas", 120, 60, 60, 61);
	m_Texas->SetInfo(70, 11, 1.05, 1950, 500, 343, 0, 
	30, 40, 0, "立即獲得12點費用；對周圍所有敵人造成兩次相當於攻擊力170%的法術傷害，並擊中目標暈眩3秒", "劍雨"
	, 2);
	m_Texas->SetZIndex(15);
	m_Texas->SetState(CharacterState::Default);
	m_Texas->SetVisible(false);
	m_Texas->SetLooping(false);
	
	// 角色擁有
	m_StartCharacter.push_back(m_Sussurro);
	m_StartCharacter.push_back(m_Exudiai);
	m_StartCharacter.push_back(m_Texas);
}

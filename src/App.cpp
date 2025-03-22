#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
#include "EnemyState.hpp"
#include "CharacterState.hpp"

void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;
    // 場景
    m_MainScream = std::make_shared<MainScream>();
    m_TT = std::make_shared<TextBox>();
    m_Root.AddChildren(m_MainScream->GetChildren());
    m_map0107=std::make_shared<Map>();
    m_0107.AddChildren(m_map0107->GetChildren());
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
	
	m_Exudiai = std::make_shared<Sniper>("Exusiai", 240, 61, 60, 60);
	
	
	m_Texas = std::make_shared<Vanguard>("Texas", 120, 60, 60, 61);
	
	
	
    //Enemy
	m_BugAs.reserve(50);
	m_BugAs.resize(50); 
	for (int i = 0; i < 1; ++i) {
		m_BugAs[i] = std::make_shared<BugA>();
		m_BugAs[i]->SetPosition({m_BugAs[i]->GetPosition().x, m_BugAs[i]->GetPosition().y + i*30.0f});
		m_BugAs[i]->SetZIndex(10);     
		m_0107.AddChild(m_BugAs[i]);
	}
    
    //m_Soldier = std::make_shared<Soldier>();
    //m_Soldier->SetZIndex(10);
    //m_Soldier->SetVisible(true);
    //m_Soldier->SetLooping(true);
    //m_Soldier->SetState(EnemyState::Idle);
    //m_Thrower = std::make_shared<Thrower>();
    //m_Varlorant = std::make_shared<Varlorant> ();

    
    //m_0107.AddChild(m_Thrower);
    //m_0107.AddChild(m_Soldier);
    //m_0107.AddChild(m_Varlorant);
}

void App::Update() {

    auto mouse=Util::Input::GetCursorPosition();
    /*if(Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
        //LOG_DEBUG(std::to_string(mouse.x)+" "+std::to_string(mouse.y));


    }*/
    if(m_level==level::lobby){
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
    if(Util::Input::IsKeyDown(Util::Keycode::Q)) {
        m_level=level::main17;
    }
    m_Root.Update();
    }
    else if(m_level==level::main17) {
        if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
            m_CurrentState = State::END;
        }
        //Debug();
        // test
        //m_Soldier->SetLooping(true);
        //m_Soldier->SetState(EnemyState::Idle);
		for (int i = 0; i < 1; ++i) {
			m_BugAs[i]->SetVisible(true);     
			m_BugAs[i]->SetLooping(true);     
			m_BugAs[i]->SetState(EnemyState::Move);
		}
        //m_BugA->SetLooping(true);
        //m_BugA->SetState(EnemyState::Idle);
        m_0107.Update();
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
// 計算兩個座標之間的距離
double App::calculateDistance(Util::Transform a, Util::Transform b) {
    return sqrt((a.translation.x - b.translation.x) * (a.translation.x - b.translation.x) + (a.translation.y - b.translation.y) * (a.translation.y - b.translation.y));
}

// 檢查滑鼠座標與物品座標之間的距離是否小於等於 range
bool App::checkCollisionNearMouse(Util::Transform Mouse, Util::Transform Item, int range) {
    double distance = calculateDistance(Mouse, Item);
    return distance <= range;
}
void App::Debug() {
    auto mouse=Util::Input::GetCursorPosition();
    Util::Transform mouseT;
    mouseT.translation=mouse;
    if(Util::Input::IsKeyDown(Util::Keycode::KP_ENTER)) {
        for(int i=0;i<m_map0107->Getblock().size();i++) {
            LOG_DEBUG( m_map0107->Getblock()[i]->m_Transform.translation);
        }
    }
    if(Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
        if(carry==false) {
            carry=false;
            for(int i=0;i<m_map0107->Getblock().size();i++) {
                if(checkCollisionNearMouse( mouseT,m_map0107->Getblock()[i]->m_Transform, 30)) {
                    m_Carry=i;
                    carry=true;
                    LOG_DEBUG("carry ");
                }
            }
            if(carry==false) {
                m_Carry=-1;
            }
        }
        else {carry=false;}
    }
    if(carry) {
        m_map0107->Getblock()[m_Carry]->m_Transform.translation=mouse;
    }


}


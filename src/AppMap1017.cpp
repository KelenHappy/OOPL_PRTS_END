#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::LevelMain17() {
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
			m_CurrentState = State::END;
    }
	// 設定角色出現與否	
	for (const auto& character : m_StartCharacter) {
		if(character->GetHP() > 0){
			character->SetLooping(true);
		}
		else{
			character->SetState(CharacterState::Die);
			if(character->IfAnimationEnds()){
				character->SetLooping(false);
				character->SetVisible(false);
			}
		}
        }
    //Debug();
	//敵人重生
	m_BugAs[0]->SetVisible(true);     
	m_BugAs[0]->SetLooping(true);     
	m_BugAs[0]->SetState(EnemyState::Move);
	
	for (size_t i = 0; i < m_BugAs.size(); ++i) {
		if(m_BugAs[i]->GetHP() > 0){
			m_BugAs[i]->SetVisible(true);     
			m_BugAs[i]->SetLooping(true);     
			m_BugAs[i]->SetState(EnemyState::Move);
		}
		else{
			m_BugAs[i]->SetState(EnemyState::Die);
			if(m_BugAs[i]->IfAnimationEnds()){
				m_BugAs[i]->SetVisible(false);     
				m_BugAs[i]->SetLooping(false);	
			}
		}
	}
	
	
    m_0107.Update();
}

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
	for (size_t i = 0; i < m_StartCharacter.size(); ++i) {
		auto& character = m_StartCharacter[i];
		CharacterState state = character->GetState();

		// 判斷是否活著
		if (character->GetHP() <= 0 and character->GetVisibility() or state == CharacterState::Die) {
			character->SetState(CharacterState::Die);
			if (character->IfAnimationEnds()) {
				character->SetLooping(false);
				character->SetVisible(false);
				// 從容器中移除死亡角色
				m_StartCharacter.erase(m_StartCharacter.begin() + i);
				--i;  // 刪除後需要調整索引
				continue;
			}
			else{
				character->SetLooping(true);
			}
		}
		else{
			character->SetLooping(true);
		}
		//判斷被放置
		
		if(carry == true and CheckCard == true) {
			// SetPosition
			if(m_StartCharacter[m_CardCarry]->GetBlockState() == m_map0107->Getblock()[m_Carry]->GetBlockState() and m_StartCharacter[m_CardCarry]->GetState() == CharacterState::Default){
				m_StartCharacter[m_CardCarry]->SetPosition(m_map0107->Getblock()[m_Carry]->GetPosition());
				m_StartCharacter[m_CardCarry]->SetState(CharacterState::Start);
				m_StartCharacter[m_CardCarry]->SetVisible(true);
			}
			
			CheckCard = false;
			carry = false;
			m_Carry = -1;
			m_CardCarry = -1;
        }
		else if(carry == false and CheckCard == true and m_StartCharacter[m_CardCarry]->GetState() == CharacterState::Default){
			
		}
		else if(carry == true and CheckCard == false and CheckCharacter){
			// 收回角色
			m_StartCharacter[m_CharacterCarry]->SetVisible(false);
			m_StartCharacter[m_CharacterCarry]->SetLooping(false);
			m_StartCharacter[m_CharacterCarry]->SetState(CharacterState::Default);
			m_Carry = -1;
			carry = false;
			m_CharacterCarry = -1;
			CheckCharacter = false;
		}
		else{
			CheckCharacter = false;
			CheckCard = false;
			carry = false;
			m_Carry = -1;
			m_CardCarry = -1;	
			m_CharacterCarry = -1;
		}
		//判斷攻擊
		for(size_t j = 0; j < m_BugAs.size() and character->GetVisibility(); ++j){
			auto& bug = m_BugAs[j];
			double distance = calculateDistance(character->m_Transform, bug->m_Transform);
			if(character->GetState() != CharacterState::Default and distance <= 150 and bug->GetVisibility()){
				character->SetState(CharacterState::Attack);
				character->SetLooping(true);
				attack(character, bug);
			}
		}
		//判斷Idle
		//有問題，拿起來重新放下無法撥動畫
		if(state == CharacterState::Start){
			if(!character->IfAnimationEnds()){
				character->SetLooping(true);
			}
			else{
				character->SetLooping(false);
				character->SetState(CharacterState::Idle);
			}
		}
	}
	

	m_BugAs[0]->SetVisible(true);
	m_BugAs[0]->SetLooping(true);
	m_BugAs[0]->SetState(EnemyState::Move);
	/*
    //Debug();
	//敵人重生


	for (size_t i = 0; i < m_BugAs.size(); ++i) {
		auto& bug = m_BugAs[i];
		if(bug->GetHP <= 0){
			bug->SetState(CharacterState::Die);
			if (bug->IfAnimationEnds()) {
				bug->SetLooping(false);
				bug->SetVisible(false);
				// 從容器中移除死亡角色
				m_BugAs.erase(m_BugAs.begin() + i);
				--i;  // 刪除後需要調整索引
			}
		}
		else {
			bugr->SetLooping(true);
		}
	}


	}*/
    m_0107.Update();
}

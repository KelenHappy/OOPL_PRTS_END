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
		// 判斷是否活著
		if (character->GetHP() <= 0) {
			character->SetState(CharacterState::Die);
			if (character->IfAnimationEnds()) {
				character->SetLooping(false);
				character->SetVisible(false);
				// 從容器中移除死亡角色
				m_StartCharacter.erase(m_StartCharacter.begin() + i);
				--i;  // 刪除後需要調整索引
				continue;
			}
		}
		else {
			character->SetLooping(true);
		}
		//判斷被放置

		//判斷攻擊

		//判斷Idle
		CharacterState state = character->GetState();
		if (!(state == CharacterState::Default ||
			state == CharacterState::Die ||
			state == CharacterState::Attack ||
			state == CharacterState::Start)) {
			character->SetState(CharacterState::Idle);
		}
	}

	m_BugAs[0]->SetVisible(true);
	m_BugAs[0]->SetLooping(true);
	m_BugAs[0]->SetState(EnemyState::Move);
	/*if (m_Sussurro->GetHP() > 0){
		m_Sussurro->SetVisible(true);
		m_Sussurro->SetLooping(true);
		m_Sussurro->SetState(CharacterState::Idle);
	}
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

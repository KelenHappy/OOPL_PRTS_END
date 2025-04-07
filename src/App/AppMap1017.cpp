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
		if ((character->GetHealthRecover() <= 0 and character->GetVisibility()) or state == CharacterState::Die) {
			character->SetState(CharacterState::Die);
			if (character->IfAnimationEnds()) {
				character->SetLooping(false);
				character->SetVisible(false);
				character->FrameReset();
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
		if(character->GetJob() != "Medic"){
			for(size_t j = 0; j < Enemies.size() and character->GetVisibility(); ++j){
				auto& bug = Enemies[j];
				double distance = calculateDistance(character->m_Transform, bug->m_Transform);
				if(character->GetState() != CharacterState::Default and distance <= character->GetAttackRangeNum()*75 and bug->GetVisibility()){
					character->SetState(CharacterState::Attack);
					character->SetLooping(true);
					attack(character, bug);
					//std::cout << bug->GetHealthRecover();
					break;
				}
				else if(character->IfAnimationEnds()){
					character->SetLooping(true);
					character->FrameReset();
					character->SetState(CharacterState::Idle);
				}
			}
		}
		// 判斷回血
		else{
			for(size_t j = 0; j < m_StartCharacter.size(); ++j){
				auto& cc = m_StartCharacter[j];
				double distance = calculateDistance(character->m_Transform, cc->m_Transform);
				if(cc->GetHP() > cc->GetHealthRecover() and distance <= character->GetAttackRangeNum()*70){
					character->SetState(CharacterState::Attack);
					character->SetLooping(true);
					attack(character, cc);
					break;
				}
				else if(character->IfAnimationEnds()){
					character->SetLooping(true);
					character->FrameReset();
					character->SetState(CharacterState::Idle);
				}
			}
		}
		//判斷Idle
		if(state == CharacterState::Start){
			if(!character->IfAnimationEnds()){
				character->SetLooping(true);
			}
			else{
				character->SetLooping(false);
				character->FrameReset();
				character->SetState(CharacterState::Idle);
			}
		}
	}
	
	//敵人
	for(size_t i = 0; i < Enemies.size(); ++i){
		auto& enemy = Enemies[i];
		EnemyState state = enemy->GetState();

		// 判斷是否活著
		
		if ((enemy->GetHealthRecover() <= 0 and enemy->GetVisibility()) or state == EnemyState::Die) {
			enemy->SetState(EnemyState::Die);
			std::cout << enemy->GetJob()<< "Die" << std::endl;
			if (enemy->IfAnimationEnds()) {
				enemy->SetLooping(false);
				enemy->SetVisible(false);
				enemy->FrameReset();
				// 從容器中移除死亡角色
				Enemies.erase(Enemies.begin() + i);
				--i;  // 刪除後需要調整索引
				continue;
			}
			else{
				enemy->SetLooping(true);
			}
		}
		else{
			enemy->SetLooping(true);
		}
		//判斷移動碰撞
		//判斷攻擊
		if(enemy->GetJob() != "None"){
			for(size_t j = 0; j < m_StartCharacter.size() and enemy->GetVisibility(); ++j){
				auto& cc = m_StartCharacter[j];
				double distance = calculateDistance(cc->m_Transform, enemy->m_Transform);
				if(enemy->GetState() != EnemyState::Default and distance <= 75 and cc->GetVisibility()){
					enemy->SetState(EnemyState::Attack);
					attack(enemy, cc);
					break;
				}
				else if(enemy->IfAnimationEnds()){
					enemy->SetLooping(true);
					enemy->FrameReset();
					enemy->SetState(EnemyState::Move);
				}
			}
		}
		// 判斷特殊角色
		else{
			
		}
		//判斷Idle
		if(state == EnemyState::Idle){
			if(!enemy->IfAnimationEnds()){
				enemy->SetLooping(true);
			}
			else{
				enemy->SetLooping(false);
				enemy->FrameReset();
				enemy->SetState(EnemyState::Idle);
			}
		}
	}
	
    m_0107.Update();
}

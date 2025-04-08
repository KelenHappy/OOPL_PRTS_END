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
	//判斷被放置
	if(carry == true and CheckCard == true) {
		// SetPosition
		if(m_StartCharacter[m_CardCarry]->GetBlockState() == m_map0107->Getblock()[m_Carry]->GetBlockState() and 
		m_StartCharacter[m_CardCarry]->GetState() == CharacterState::Default and
		m_map0107->Takemapcost(m_StartCharacter[m_CardCarry]->GetSetCost())){
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
	// 設定角色出現與否
	for (size_t i = 0; i < m_StartCharacter.size(); ++i) {
		CharacterState state = m_StartCharacter[i]->GetState();

		// 判斷是否活著
		if ((m_StartCharacter[i]->GetHealthRecover() <= 0 and m_StartCharacter[i]->GetVisibility()) or state == CharacterState::Die) {
			m_StartCharacter[i]->SetState(CharacterState::Die);
			if (m_StartCharacter[i]->IfAnimationEnds()) {
				m_StartCharacter[i]->SetLooping(false);
				m_StartCharacter[i]->SetVisible(false);
				m_StartCharacter[i]->FrameReset();
				// 從容器中移除死亡角色
				m_StartCharacter.erase(m_StartCharacter.begin() + i);
				--i;  // 刪除後需要調整索引
				continue;
			}
			else{
				m_StartCharacter[i]->SetLooping(true);
			}
		}
		else{
			m_StartCharacter[i]->SetLooping(true);
		}
		//判斷攻擊
		if(m_StartCharacter[i]->GetJob() != "Medic"){
			for(size_t j = 0; j < Enemies.size() and m_StartCharacter[i]->GetVisibility(); ++j){
				auto& bug = Enemies[j];
				double distance = calculateDistance(m_StartCharacter[i]->m_Transform, bug->m_Transform);
				if(m_StartCharacter[i]->GetState() != CharacterState::Default and distance <= m_StartCharacter[i]->GetAttackRangeNum()*75 and bug->GetVisibility()){
					m_StartCharacter[i]->SetState(CharacterState::Attack);
					m_StartCharacter[i]->SetLooping(true);
					attack(m_StartCharacter[i], bug);
					break;
				}
			}
		}
		// 判斷回血
		else if(m_StartCharacter[i]->GetJob() == "Medic"){
			for(size_t j = 0; j < m_StartCharacter.size() and m_StartCharacter[i]->GetVisibility(); ++j){
				double distance = calculateDistance(m_StartCharacter[i]->m_Transform, m_StartCharacter[j]->m_Transform);
				if(j !=i and m_StartCharacter[j]->GetHP() > m_StartCharacter[j]->GetHealthRecover() and 
				distance <= m_StartCharacter[i]->GetAttackRangeNum()*70){
					m_StartCharacter[i]->SetState(CharacterState::Attack);
					m_StartCharacter[i]->SetLooping(true);
					attack(m_StartCharacter[i], m_StartCharacter[j]);
					break;
				}
			}
		}
		//判斷Idle
		if (m_StartCharacter[i]->IfAnimationEnds() and m_StartCharacter[i]->GetState() != CharacterState::Default) {
			m_StartCharacter[i]->SetVisible(true);
			m_StartCharacter[i]->SetLooping(true);
			m_StartCharacter[i]->FrameReset();
			m_StartCharacter[i]->SetState(CharacterState::Idle);
		}
	}
	//敵人
	for(size_t i = 0; i < Enemies.size(); ++i){
		EnemyState state = Enemies[i]->GetState();

		// 判斷是否活著
		
		if ((Enemies[i]->GetHealthRecover() <= 0 and Enemies[i]->GetVisibility()) or state == EnemyState::Die) {
			Enemies[i]->SetState(EnemyState::Die);
			//std::cout << enemy->GetJob()<< "Die" << std::endl;
			if (Enemies[i]->IfAnimationEnds()) {
				Enemies[i]->SetLooping(false);
				Enemies[i]->SetVisible(false);
				Enemies[i]->FrameReset();
				// 從容器中移除死亡角色
				Enemies.erase(Enemies.begin() + i);
				--i;  // 刪除後需要調整索引
				continue;
			}
			else{
				Enemies[i]->SetLooping(true);
			}
		}
		else{
			Enemies[i]->SetLooping(true);
		}
		//判斷移動碰撞
		//判斷攻擊
		if(Enemies[i]->GetJob() != "None"){
			for(size_t j = 0; j < m_StartCharacter.size() and Enemies[i]->GetVisibility(); ++j){
				double distance = calculateDistance(m_StartCharacter[j]->m_Transform, Enemies[i]->m_Transform);
				if(Enemies[i]->GetState() != EnemyState::Default and distance <= 75 and m_StartCharacter[j]->GetVisibility()){
					Enemies[i]->SetState(EnemyState::Attack);
					attack(Enemies[i], m_StartCharacter[j]);
					break;
				}
				else if(Enemies[i]->IfAnimationEnds()){
					Enemies[i]->SetLooping(true);
					Enemies[i]->FrameReset();
					Enemies[i]->SetState(EnemyState::Move);
				}
			}
		}
		// 判斷特殊角色
		else{
			
		}
		//判斷Idle
		if(state == EnemyState::Idle){
			if(!Enemies[i]->IfAnimationEnds()){
				Enemies[i]->SetLooping(true);
			}
			else{
				Enemies[i]->SetLooping(false);
				Enemies[i]->FrameReset();
				Enemies[i]->SetState(EnemyState::Idle);
			}
		}
	}
	
    m_0107.Update();
}

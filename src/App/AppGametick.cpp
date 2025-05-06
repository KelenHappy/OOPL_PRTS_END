#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>

void App::GameTick() {
    for(size_t i = 0; i< Enemies.size(); i++) {
        if(Enemies[i]->GetVisibility()) {
           Enemies[i]->Updatemove();
            if(Enemies[i]->GetPathPointsindex() >= static_cast<int>(Enemies[i]->GetPathPoints()->GetPointsize())) {
                m_map0107->EmenyEnterTower();
            	m_map0107->EnemyDied();
                Enemies[i]->SetVisible(false);
            	Enemies[i]->GetHpBar()->SetVisible(false);
                Enemies[i]->SetLooping(false);
			}
        }
    }
    for (size_t i = 0; i < m_LevelCharacter.size(); ++i) {
		if(!m_LevelCharacter[i]->GetVisibility()) continue;
		CharacterState state = m_LevelCharacter[i]->GetState();
		// 判斷是否活著
		if ((m_LevelCharacter[i]->GetHealthRecover() <= 0) or state == CharacterState::Die) {
			m_LevelCharacter[i]->SetState(CharacterState::Die);
			if (m_LevelCharacter[i]->IfAnimationEnds()) {
				m_LevelCharacter[i]->OutPlaceCharacter();
				m_LevelCharacter[i]->FrameReset();
				// 從容器中Reset角色
				m_LevelCharacter[i]->SetDead(true);
				continue;
			}
			else{
				m_LevelCharacter[i]->SetLooping(true);
				continue;
			}
		}
		else{
			m_LevelCharacter[i]->SetLooping(true);
		}
		//判斷攻擊
		if(m_LevelCharacter[i]->GetAttackType() != CharacterAttackType::Health){
			for(size_t j = 0; j < Enemies.size() ; ++j){
				float distance = calculateDistance(m_LevelCharacter[i]->m_Transform, Enemies[j]->m_Transform);
				if(state != CharacterState::Default and distance <= m_LevelCharacter[i]->GetAttackRangeNum()*75
				and Enemies[j]->GetVisibility()
				and m_LevelCharacter[i]->IfAnimationEnds()){
					m_LevelCharacter[i]->SetState(CharacterState::Attack);
					for(int k = 0; k < m_LevelCharacter[i]->GetAttackTimesBuff();k++){
						attack(m_LevelCharacter[i], Enemies[j]);
						std::shared_ptr<TakeDamage> tempFilm = std::make_shared<TakeDamage>(Enemies[j]->GetName(),"takeDamage");
						tempFilm->SetPosition(Enemies[j]->GetPositionFix());
						m_FilmVector.push_back(tempFilm);
						m_0107.AddChild(tempFilm);
						if(m_LevelCharacter[i]->GetJob() == "Sniper"){
							std::shared_ptr<Bullet> tempB = std::make_shared<Bullet> (m_LevelCharacter[i]->GetCharacterName(), "Bullet");
							tempB->SetPosition(m_LevelCharacter[i]->GetPosition());
							tempB->SetEnemyPoint(Enemies[j]->GetPositionFix());
							m_FilmVector.push_back(tempB);
							m_0107.AddChild(tempB);
						}
					}
					break;
				}
				else if(m_LevelCharacter[i]->IfAnimationEnds()){
					m_LevelCharacter[i]->SetState(CharacterState::Idle);
				}
			}
		}
		// 判斷回血
		else if(m_LevelCharacter[i]->GetAttackType() == CharacterAttackType::Health){
			for(size_t j = 0; j < m_LevelCharacter.size(); ++j){
				float distance = calculateDistance(m_LevelCharacter[i]->m_Transform, m_LevelCharacter[j]->m_Transform);
				if(m_LevelCharacter[j]->GetHP() > m_LevelCharacter[j]->GetHealthRecover()
				and distance <= m_LevelCharacter[i]->GetAttackRangeNum()*75
				and m_LevelCharacter[i]->IfAnimationEnds()){
					m_LevelCharacter[i]->SetState(CharacterState::Attack);
					for(int k; k < m_LevelCharacter[i]->GetAttackTimesBuff();k++){
						attack(m_LevelCharacter[i], m_LevelCharacter[j]);
					}
					break;
				}
				else if(m_LevelCharacter[i]->IfAnimationEnds()){
					m_LevelCharacter[i]->SetState(CharacterState::Idle);
				}
			}
		}
		//判斷Idle
		if (m_LevelCharacter[i]->IfAnimationEnds()
		and state != CharacterState::Default and state != CharacterState::Die and state != CharacterState::Attack) {
			m_LevelCharacter[i]->SetVisible(true);
			m_LevelCharacter[i]->SetLooping(true);
			m_LevelCharacter[i]->SetState(CharacterState::Idle);
			m_LevelCharacter[i]->FrameReset();
		}

	}
	//敵人
	for(size_t i = 0; i < Enemies.size(); ++i){
		EnemyState state = Enemies[i]->GetState();
		if(!Enemies[i]->GetVisibility()) continue;
		// 判斷是否活著
		if (Enemies[i]->GetHealthRecover() <= 0 or state == EnemyState::Die) {
			Enemies[i]->SetState(EnemyState::Die);
			//std::cout << enemy->GetJob()<< "Die" << std::endl;
			if (Enemies[i]->IfAnimationEnds()) {
				Enemies[i]->SetLooping(false);
				Enemies[i]->SetVisible(false);
				Enemies[i]->GetHpBar()->SetVisible(false);
				Enemies[i]->FrameReset();
				// 從容器中移除死亡角色
				m_map0107->EnemyDied();
				m_0107.RemoveChild(Enemies[i]);
				--i;  // 刪除後需要調整索引
				continue;
			}
			else{
				Enemies[i]->SetLooping(true);
				continue;
			}
		}
		else{
			Enemies[i]->SetLooping(true);
		}
		//判斷移動碰撞
		//判斷攻擊
		int Count = Enemies[i]->GetAttackTimesBuff();
		if(Enemies[i]->GetJob() != "None"){
			for(size_t j = 0; j < m_LevelCharacter.size(); ++j){
				float distance = calculateDistance(m_LevelCharacter[j]->m_Transform, Enemies[i]->m_Transform);
				if(state != EnemyState::Default and distance <= Enemies[i]->GetAttackRangeNum()* 70 and m_LevelCharacter[j]->GetVisibility()
					and Enemies[i]->IfAnimationEnds()){
					Enemies[i]->SetState(EnemyState::Attack);
					attack(Enemies[i], m_LevelCharacter[j]);
					Count--;
					if(Count <= 0){break;}
					else{continue;}
				}
				else if(Enemies[i]->IfAnimationEnds()){
					Enemies[i]->SetState(EnemyState::Move);
				}
			}
		}
		// 判斷特殊角色
		else{

		}
		if(Enemies[i]->IfAnimationEnds()
		and state != EnemyState::Default and state != EnemyState::Die and state != EnemyState::Attack){
			Enemies[i]->SetLooping(true);
			Enemies[i]->SetVisible(true);
			Enemies[i]->SetState(EnemyState::Move);
			Enemies[i]->FrameReset();
		}
	}
	if(Enemies.size() == 0){
		for(size_t i = 0; i < m_LevelCharacter.size() and m_LevelCharacter[i]->GetVisibility(); i++){
			m_LevelCharacter[i]->SetVisible(true);
			m_LevelCharacter[i]->SetLooping(true);
			m_LevelCharacter[i]->SetState(CharacterState::Idle);
		}
	}
	for (size_t i = 0; i < m_FilmVector.size(); i++) {
		if (!m_FilmVector[i]) {
			continue;
		}

		m_FilmVector[i]->Update();

		if (m_FilmVector[i]->GetNowLife() <= 0) {
			m_FilmVector[i]->SetVisible(false);
			m_0107.RemoveChild(m_FilmVector[i]);
			m_FilmVector.erase(m_FilmVector.begin() + i);
			--i;
		}
	}
}

#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>

#include "Film/Frozen.hpp"

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
				for (size_t j = 0; i < m_LevelCharacter[j]->GetGotEnemy().size(); j ++) {
					m_LevelCharacter[i]->GetGotEnemy()[j]->SetStuck(false);
				}
				m_LevelCharacter[i]->GetGotEnemy().clear();
				m_LevelCharacter[i]->CloseSkill();
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
		if(m_LevelCharacter[i]->GetVisibility() and m_LevelCharacter[i]->GetAttackTimeTicket() > 0){
			m_LevelCharacter[i]->DeAttackTime();
		}
		if(m_LevelCharacter[i]->GetAttackType() != CharacterAttackType::Health){
			int k = 0;
			std::vector<std::shared_ptr<Enemy>>  EnemyTools = GetCharaterEnemyinRange(m_LevelCharacter[i]);
			if (EnemyTools.size()>0  and m_LevelCharacter[i]->IfAnimationEnds() and m_LevelCharacter[i]->GetAttackTimeTicket() <= 0 and state != CharacterState::Default) {
				m_LevelCharacter[i]->FrameReset();
				for(size_t j = 0; j < EnemyTools.size() and j < static_cast<size_t>(m_LevelCharacter[i]->GetAttackTimesBuff()); ++j){
					m_LevelCharacter[i]->SetState(CharacterState::Attack);
					if(k < m_LevelCharacter[i]->GetAttackTimesBuff()){
						//std::cout << EnemyTools[0]->GetVisibility() << std::endl;
						//std::cout << "Attack" << EnemyTools[j]->GetName() << std::endl;
						//std::cout <<"AttackTimes"<< m_LevelCharacter[i]->AttackTimess << std::endl;
						for (int AttackTimes = 0 ; AttackTimes < m_LevelCharacter[i]->AttackTimess; AttackTimes++){attack(m_LevelCharacter[i], EnemyTools[j]);}
						if(m_LevelCharacter[i]->GetJob() == "Sniper"){
							std::shared_ptr<Bullet> tempB = std::make_shared<Bullet> (m_LevelCharacter[i]->GetCharacterName(), "Bullet");
							tempB->SetPosition(m_LevelCharacter[i]->GetPosition());
							tempB->SetEnemyPoint(EnemyTools[j]->GetPositionFix());
							m_FilmVector.push_back(tempB);
							m_0107.AddChild(tempB);
						}
						if (m_LevelCharacter[i]->GetAttackImpact() == CharacterAttackImpact::Frozen) {
							std::shared_ptr<Frozen>tempF = std::make_shared<Frozen>(m_LevelCharacter[i]->GetCharacterName(), "Frozen");
							tempF->SetPosition(EnemyTools[j]->GetPositionFix());
							m_FilmVector.push_back(tempF);
							m_0107.AddChild(tempF);
						}
						else {
							std::shared_ptr<TakeDamage> tempFilm = std::make_shared<TakeDamage>(EnemyTools[j]->GetName(),"takeDamage");
							tempFilm->SetPosition(EnemyTools[j]->GetPositionFix());
							m_FilmVector.push_back(tempFilm);
							m_0107.AddChild(tempFilm);
						}
						k++;
						continue;
					}
					m_LevelCharacter[i]->SetAttackTimeTicket(m_LevelCharacter[i]->GetAttackTime()*20);
					//std::cout << m_LevelCharacter[i]->GetAttackTimeTicket() << std::endl;
					break;
				}
				if(m_LevelCharacter[i]->IfAnimationEnds()) {
					m_LevelCharacter[i]->SetState(CharacterState::Idle);
				}
			}
		}
		// 判斷回血
		else if(m_LevelCharacter[i]->GetAttackType() == CharacterAttackType::Health){
			int k = 0;
			std::vector<std::shared_ptr<AnimatedCharacter>>   CharacterTools = GetCharaterinRange(m_LevelCharacter[i]);
			if (CharacterTools.size()>0  and m_LevelCharacter[i]->IfAnimationEnds() and m_LevelCharacter[i]->GetAttackTimeTicket() <= 0 and state != CharacterState::Default) {
				m_LevelCharacter[i]->FrameReset();
				for(size_t j = 0; j < CharacterTools.size() and j < static_cast<size_t>(m_LevelCharacter[i]->GetAttackTimesBuff()); ++j){
					m_LevelCharacter[i]->SetState(CharacterState::Attack);
					if(k < m_LevelCharacter[i]->GetAttackTimesBuff() and m_LevelCharacter[j]->GetHP() > m_LevelCharacter[j]->GetHealthRecover()){

						//std::cout <<"AttackTimes"<< m_LevelCharacter[i]->AttackTimess << std::endl;
						for (int AttackTimes = 0 ; AttackTimes < m_LevelCharacter[i]->AttackTimess; AttackTimes++){attack(m_LevelCharacter[i], CharacterTools[j]);}
						k++;
						continue;
					}
					m_LevelCharacter[i]->SetAttackTimeTicket(m_LevelCharacter[i]->GetAttackTime()*20);
					//std::cout << m_LevelCharacter[i]->GetAttackTimeTicket() << std::endl;
					break;
				}
				if(m_LevelCharacter[i]->IfAnimationEnds()) {
					m_LevelCharacter[i]->SetState(CharacterState::Idle);
				}
			}
		}
    	//被敵人攻擊
    	auto temp = m_LevelCharacter[i]->GetGotEnemy();
    	for (size_t k = 0; k < temp.size(); k ++) {
    		if (temp[k]->GetAttackTicket() < 0 and temp[k]->IfAnimationEnds()) {
    			temp[k]->SetState(EnemyState::Attack);
    			attack(temp[k], m_LevelCharacter[i]);
    			temp[k]->SetAttackTicket(temp[k]->GetAttackSpeed()*20);
    		}
    		else {
    			temp[k]->DeAttakSpeedTime(1);
    		}
    		if (temp[k]->IfAnimationEnds()) {
    			temp[k]->SetState(EnemyState::Idle);
    		}
    	}
		//判斷Idle
		if (m_LevelCharacter[i]->IfAnimationEnds()
		and state != CharacterState::Default and state != CharacterState::Die) {
			m_LevelCharacter[i]->SetVisible(true);
			m_LevelCharacter[i]->SetLooping(true);
			m_LevelCharacter[i]->SetState(CharacterState::Idle);
			m_LevelCharacter[i]->FrameReset();
		}

	}
	//敵人
	for(size_t i = 0; i < Enemies.size(); ++i){
		if(!Enemies[i]->GetVisibility() and Enemies[i]->GetState() == EnemyState::Default) continue;
		if (Enemies[i]->GetStuck()) {
			Enemies[i]->DeAttakSpeedTime(1);
		}
		EnemyState state = Enemies[i]->GetState();
		// 判斷是否活著
		if (Enemies[i]->GetHealthRecover() <= 0 or state == EnemyState::Die or Enemies[i]->GetIsDead()) {
			Enemies[i]->SetState(EnemyState::Die);
			Enemies[i]->SetIsDead(true);
			if (Enemies[i]->GetStuck()) {
				for (auto character : m_LevelCharacter) {
					auto gotEnemies = character->GetGotEnemy();
					gotEnemies.clear();
				}
				Enemies[i]->SetStuck(false);
			}
			//std::cout << enemy->GetJob()<< "Die" << std::endl;
			if (Enemies[i]->IfAnimationEnds()) {
				Enemies[i]->SetLooping(false);
				Enemies[i]->SetVisible(false);
				Enemies[i]->GetHpBar()->SetVisible(false);
				Enemies[i]->FrameReset();
				// 從容器中移除死亡角色
				m_map0107->EnemyDied();
				Enemies.erase(Enemies.begin() + i);
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
		if(Enemies[i]->GetJob() != "None"){
			for(size_t j = 0; j < m_LevelCharacter.size() ; ++j) {
				m_LevelCharacter[j]->GetGotEnemy().clear();
				if (m_LevelCharacter[j]->GetHeavyLevel() <= m_LevelCharacter[j]->GetGotEnemy().size()) {
					continue;
				}
				float distance = glm::length(m_LevelCharacter[j]->GetPositionFix()-Enemies[i]->GetPositionFix()) ;
				if(state != EnemyState::Default and state != EnemyState::Die and distance <= Enemies[i]->GetAttackRangeNum()* 70 and m_LevelCharacter[j]->GetVisibility()
					and Enemies[i]->IfAnimationEnds()){
					m_LevelCharacter[j]->AppendDefendEnemy(Enemies[i]);
					Enemies[i]->SetStuck(true);
				}
				else if(Enemies[i]->IfAnimationEnds()){
					if(Enemies[i]->GetRodeWaitTime()>1) Enemies[i]->SetState(EnemyState::Idle);
					else Enemies[i]->SetState(EnemyState::Move);
				}
			}
		}
		// 判斷特殊角色
		else{

		}
		if(Enemies[i]->IfAnimationEnds()and state != EnemyState::Default and state != EnemyState::Die){
			Enemies[i]->SetLooping(true);
			Enemies[i]->SetVisible(true);
			if(Enemies[i]->GetRodeWaitTime()>1) Enemies[i]->SetState(EnemyState::Idle);
			else Enemies[i]->SetState(EnemyState::Move);
			Enemies[i]->FrameReset();
		}
	}

	//結束與特效

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

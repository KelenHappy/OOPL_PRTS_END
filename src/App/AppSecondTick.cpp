#include "App.hpp"
#include  <string>
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>

void App::GameSecondTick() {
    m_map0107->Addmapcost(1);
    m_map0107->UpdateCard();
    for(size_t i = 0; i < m_LevelCharacter.size(); i++){
        if(m_LevelCharacter[i]->GetDie()){
            /*
            bool checkFirst = true;
            m_LevelCharacter[i]->DeDieCost(1);



            for (size_t j = 0; j < m_FilmVector.size(); j++) {
                std::string characterName = m_LevelCharacter[i]->GetCharacterName();
                if (characterName + "die" == m_FilmVector[j]->GetName()) {
                    checkFirst = false;
                    break;
                }
            }

            if(checkFirst){
				std::shared_ptr<Film> tempFilm = std::make_shared<Film>(m_LevelCharacter[i]->GetCharacterName(),"die", FilmState::Die);
				tempFilm->SetLifeTimes(m_LevelCharacter[i]->GetSetTime()*20);
				tempFilm->SetPosition(m_map0107->GetCard()[i]->GetPosition());
                m_FilmVector.push_back(tempFilm);
                std::cout << "Add Film" << std::endl;
                m_0107.AddChild(tempFilm);
            }*/
        }
        else{
            if(!m_LevelCharacter[i]->GetSkillOpen() and m_LevelCharacter[i]->GetVisibility()){m_LevelCharacter[i]->AddSkillCost(1);}

            else if (m_LevelCharacter[i]->GetSkillDefault() == 0 and !m_LevelCharacter[i]->GetSkillOpen() and m_LevelCharacter[i]->GetVisibility() and m_LevelCharacter[i]->GetSkillCost() < m_LevelCharacter[i]->GetSkillNow()) {
                m_LevelCharacter[i]->OpenSkill();
                std::cout << m_LevelCharacter[i]->GetCharacterName() << " Open Skill" << std::endl;
            }
            else if(m_LevelCharacter[i]->GetSkillOpen()){
                std::cout << m_LevelCharacter[i]->GetSkillTime() << std::endl;
                m_LevelCharacter[i]->DeSkillTime(1);
                if(m_LevelCharacter[i]->GetSkillTime() <= 0 and m_LevelCharacter[i]->GetVisibility() and m_LevelCharacter[i]->GetSkillOpen()){
                    m_LevelCharacter[i]->CloseSkill();
                }
            }
        }
        if(m_LevelCharacter[i]->GetDieCost() <= 0){
            m_LevelCharacter[i]->SetHP();
            m_LevelCharacter[i]->SetDieCost();
            m_LevelCharacter[i]->SetDead(false);
            m_LevelCharacter[i]->SetLooping(true);
            m_LevelCharacter[i]->SetState(CharacterState::Default);
        }
    }
    for (size_t i =0; i < Enemies.size(); i++) {
        if(Enemies[i]->GetVisibility()){
            Enemies[i]->UpdateEffect();
            if(Enemies[i]->GetImpactTick() > 0 and Enemies[i]->GetImpactBB())Enemies[i]->DeImpactTick();
            else{
                Enemies[i]->FullSpeedMove();
            }
        }
    }
    for (size_t i = 0; i < m_LevelCharacter.size(); i++) {
        if(m_LevelCharacter[i]->GetVisibility())m_LevelCharacter[i]->UpdateEffect();
        if(m_LevelCharacter[i]->GetVisibility() and m_LevelCharacter[i]->BuffTicket)m_LevelCharacter[i]->UpdateBuffTime();
    }
    m_map0107->Update();
    m_Spawner->Update();
    if(m_map0107->GetEnemytotal() ==m_map0107->GetEnemytotalMax() ){
        gametimer->Reset();
        gametimer->Pause();
        m_map0107->End();
        std::cout<<"isend";
    }

}

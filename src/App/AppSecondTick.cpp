#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>

void App::GameSecondTick() {
    m_map0107->Addmapcost(1);

    for(size_t i = 0; i < m_LevelCharacter.size(); i++){
        if(m_LevelCharacter[i]->GetDie()){
            bool checkFirst = true;
            m_LevelCharacter[i]->DeDieCost(1);
			
			
            for (size_t j = 0; j < m_FilmVector.size(); j++) {
                if (m_LevelCharacter[i]->GetCharacterName() + "die" == m_FilmVector[j]->GetName()) {
                    checkFirst = false;
                    break;
                }
            }
			
            if(checkFirst){
				std::shared_ptr<Film> tempFilm = std::make_shared<Film>(m_LevelCharacter[i]->GetCharacterName(),"die");
				tempFilm->SetLifeTimes(m_LevelCharacter[i]->GetSetTime()*20);
				tempFilm->SetPosition(m_map0107->GetCard()[i]->GetPosition());
                m_FilmVector.push_back(tempFilm);
                std::cout << "Add Film" << std::endl;
                m_0107.AddChild(tempFilm);
            }
        }
        else{
            if(!m_LevelCharacter[i]->GetSkillOpen()){m_LevelCharacter[i]->AddSkillCost(1);}
            else{
                m_LevelCharacter[i]->DeSkillTime(1);
                if(m_LevelCharacter[i]->GetSkillTime() <= 0){
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
    m_map0107->Update();
    m_Spawner->Update();

}

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
        m_LevelCharacter[i]->AddSkillCost(1);
        if(m_LevelCharacter[i]->GetDie()){
            m_LevelCharacter[i]->DeDieCost(1);
        }
        if(m_LevelCharacter[i]->GetDieCost() <= 0){
            m_LevelCharacter[i]->SetHP();
            m_LevelCharacter[i]->SetDieCost();
            m_LevelCharacter[i]->SetDead(false);
            m_LevelCharacter[i]->SetLooping(true);
        }
    }
    m_map0107->Update();
    m_Spawner->Update();

}

#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::OpenSkillOther(std::shared_ptr<AnimatedCharacter> Charater) {
    if(Charater->GetCharacterName()=="Myrtle") {
        m_map0107->Addmapcost(16);
    }
    else if(Charater->GetCharacterName()=="Texas") {
        m_map0107->Addmapcost(12);
    }
    else if(Charater->GetCharacterName()=="Ines") {
        m_map0107->Addmapcost(14);
    }
    else if(Charater->GetCharacterName()=="Texas_the_Omertosa") {
        std::vector<std::shared_ptr<Enemy>>  EnemyTools = GetCharaterEnemyinRange(Charater);
        for(size_t i=0;i<EnemyTools.size();i++){
        for (int AttackTimes = 0 ; AttackTimes < 2; AttackTimes++) {
            attack(Charater, EnemyTools[i]);
        }
        }
    }
}

#include "CharacterAttackImpact.hpp"
#include <iostream>
template <typename T1, typename T2>
void attack(T1 &thisC, T2 &that){
    float damage = thisC.GetAttack();
    switch(thisC.GetAttackType()){
        case CharacterAttackType::Physics:
            damage -= that.GetDefend();
            break;
        case CharacterAttackType::Magic:
            damage = damage*( (100 - that.GetMagicDefend())/100);
            break;
        default:
            std::cout << "Take Damage Error." << std::endl;
            break;
    }
    that.takeDamage(
        thisC.GetAttackImpact(),
        damage);
}


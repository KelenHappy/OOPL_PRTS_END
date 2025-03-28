#include "CharacterAttackImpact.hpp"
#include <iostream>
template <typename T1, typename T2>
void attack(T1 &this, T2 &that){
    float damage = this.GetAttack();
    switch(this.GetAttackType()){
        case CharacterAttackType::Physics:
            damage -= that.GetDefend();
            break;
        case CharacterAttackType::Magic:
            damage -= that.GetMagicDefend();
            break;
        default:
            std::cout << "Take Damage Error." << std::endl;
            break;
    }
    that.takeDamage(
        this.GetAttackImpact(),
        damage);
}

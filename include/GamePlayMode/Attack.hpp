#ifndef ATTACK_HPP
#define ATTACK_HPP
#include "CharacterAttackImpact.hpp"
#include <iostream>
template <typename T1, typename T2>
void attack(T1 thisC, T2 that){
	if(thisC == nullptr or that == nullptr){
		std::cout << "Attack Error" << std::endl;
	}
    float damage = thisC->GetAttack();
    switch(thisC->GetAttackType()){
        case CharacterAttackType::Physics:
            damage -= that->GetDefend();
            break;
        case CharacterAttackType::Magic:
            damage = damage*( (100 - that->GetMagicDefend())/100);
            break;
        default:
            std::cout << "Take Damage Error." << std::endl;
            break;
    }
    damage = glm::max(thisC->GetAttack()*0.02f,damage);
    that->takeDamage(
        thisC->GetAttackImpact(),
        damage);
}
#endif

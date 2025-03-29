#include "Enemy/Enemy.hpp"

void Enemy::takeDamage(CharacterAttackImpact impact, float damage){
	switch(impact){
		case CharacterAttackImpact::Null:
			break;
		case CharacterAttackImpact::Dizzy:
			ImpactDizzy();
			break;
		case CharacterAttackImpact::Sleep:
			ImpactSleep();
			break;
		case CharacterAttackImpact::Frozen:
			ImpactFrozen();
			break;
		default:
			std::cout << "Take DamageError." << std::endl;
			break;
	}
	HealthNum -= damage;
}
void Enemy::ImpactDizzy(){

}

void Enemy::ImpactSleep(){

}

void Enemy::ImpactFrozen(){

}
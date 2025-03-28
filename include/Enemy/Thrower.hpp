#ifndef THROWER_HPP
#define THROWER_HPP
#include "Enemy.hpp"
#include "AnimatedCharacter.hpp"
class Thrower : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    Thrower() : Enemy("Thrower", 61, 91, 61, 60){
		//int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
		//, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
		//, bool Dizzy, bool Sleep, bool Frozen
		//, AttackType attack_t
		SetInfo(1550, 180, 50, 0, 2.7,
		1.75, 1, 1.0, 0, 0,
		false, false, false,
		CharacterAttackType::Physics);
    }



private:

};

#endif

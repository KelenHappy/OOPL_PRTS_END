#ifndef VARLORANT_HPP
#define VARLORANT_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class Varlorant : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    Varlorant() : Enemy("Varlorant", 59, 62, 57, 57){
		//int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
		//, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
		//, bool Dizzy, bool Sleep, bool Frozen
		//, AttackType attack_t
		SetInfo(1700, 250, 50, 0, 2.0,
		0, 1, 1.0, 0, 0,
		false, false, false,
		CharacterAttackType::Physics);
    }
	std::string GetName(){
		return "Varlorant";
	}
	~Varlorant(){}


private:

};

#endif



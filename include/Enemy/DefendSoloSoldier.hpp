#ifndef DEFEND_SOLO_SOLDIER_HPP
#define DEFEND_SOLO_SOLDIER_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class DefendSoloSoldier : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    DefendSoloSoldier() : Enemy("DefendSoloSoldier", 40, 20, 12, 13){
		//int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
		//, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel
		//, bool Dizzy, bool Sleep, bool Frozen
		//, AttackType attack_t
		SetInfo(8000, 700, 1000, 0, 3.0,
		1, 0.7, 0.7,4,
		false, false, false,
		CharacterAttackType::Physics);
    }
	std::string GetName() override{
		return "DefendSoloSoldier";
	}
	~DefendSoloSoldier(){}


private:

};

#endif

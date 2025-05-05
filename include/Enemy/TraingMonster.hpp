#ifndef TRAING_MONSTER_HPP
#define TRAING_MONSTER_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class TraingMonster : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    TraingMonster() : Enemy("TraingMonster", 79, 70, 59, 58){
		//int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
		//, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
		//, bool Dizzy, bool Sleep, bool Frozen
		//, AttackType attack_t
		SetInfo(2000, 380, 450, 30, 2.5,
		1, 1, 1.0, 0,
		false, false, false,
		CharacterAttackType::Physics);
    }
	std::string GetName() override{
		return "TraingMonster";
	}
	~TraingMonster(){}


private:

};

#endif

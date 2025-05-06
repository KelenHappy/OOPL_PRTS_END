#ifndef SOLDIER_STUDENT_HPP
#define SOLDIER_STUDENT_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class SoldierStudent : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    SoldierStudent() : Enemy("SoldierStudent", 20, 13, 68, 57){
		//int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
		//, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
		//, bool Dizzy, bool Sleep, bool Frozen
		//, AttackType attack_t
		SetInfo(2800, 300, 100, 0, 2.4,
		2, 1, 1.0, 0,
		false, false, false,
		CharacterAttackType::Physics);
		// Attack Range
		SetAttackRangeNum(2);
    }
	std::string GetName() override{
		return "SoldierStudent";
	}
	~SoldierStudent(){}


private:

};

#endif

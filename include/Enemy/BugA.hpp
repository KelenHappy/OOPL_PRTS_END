#ifndef BUGA_HPP
#define BUGA_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class BugA : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    BugA() : Enemy("Bug_A", 20, 47, 31, 20){
		//int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
		//, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
		//, bool Dizzy, bool Sleep, bool Frozen
		//, AttackType attack_t
		SetInfo(1050, 185, 0, 0, 1.7, 
		1, 1, 1.0, 0,
		false, false, false, 
		CharacterAttackType::Physics);
    }
	std::string GetName() override{
		return "BugA";
	}
	~BugA(){}



private:
	
};

#endif

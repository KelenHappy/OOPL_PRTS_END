#ifndef SOLDIER_HPP
#define SOLDIER_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class Soldier : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    Soldier() : Enemy("Soldier", 59, 61, 60, 62){
		//int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
		//, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
		//, bool Dizzy, bool Sleep, bool Frozen
		//, AttackType attack_t
		SetInfo(1650, 200, 100, 0, 2.0,
		0, 1, 1.1, 0,
		false, false, false,
		CharacterAttackType::Physics);
    }
	std::string GetName() override{
		return "Soldier";
	}
	~Soldier(){}


private:

};

#endif

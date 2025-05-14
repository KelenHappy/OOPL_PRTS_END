#ifndef NO_NAME_SOLDIER_HPP
#define NO_NAME_SOLDIER_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class NoNameSoldier : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    NoNameSoldier() : Enemy("NoNameSoldier", 20, 54, 57, 48){
		//int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
		//, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
		//, bool Dizzy, bool Sleep, bool Frozen
		//, AttackType attack_t
		SetInfo(2800, 280, 150, 0, 2.0,
		1, 1, 1.1, 0,
		false, false, false,
		CharacterAttackType::Physics);
    }
	std::string GetName() override{
		return "NoNameSoldier";
	}
	~NoNameSoldier(){}


private:

};

#endif

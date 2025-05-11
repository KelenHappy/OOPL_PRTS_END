#ifndef  ComplieMagic_HPP
#define  ComplieMagic_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class ComplieMagic : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    ComplieMagic() : Enemy("ComplieMagic", 58, 89, 58, 62){
		//int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
		//, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
		//, bool Dizzy, bool Sleep, bool Frozen
		//, AttackType attack_t
		SetInfo(3000, 320, 100, 50, 4.0,
		1.8, 0.8, 1, 0,
		false, false, false,
		CharacterAttackType::Magic);
		// Attack Range
		SetAttackRangeNum(1.8);
    }
	std::string GetName() override{
		return "ComplieMagic";
	}
	~ComplieMagic(){}


private:

};

#endif

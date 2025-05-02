#ifndef CRAZY_HOST_THROWER_HPP
#define CRAZY_HOST_THROWER_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class CrazyHostThrower : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    CrazyHostThrower() : Enemy("CrazyHostThrower", 118, 77, 57, 118){
        //int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
        //, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
        //, bool Dizzy, bool Sleep, bool Frozen
        //, AttackType attack_t
        SetInfo(15000, 750, 200, 30, 2.0,
        2.6,1, 0.7, 2,
        false, false, false,
        CharacterAttackType::Physics);
        // Attack Range
        SetAttackRangeNum(2.6);
    }
    std::string GetName() override{
        return "CrazyHostThrower";
    }
    void UpdateEffect() override {
        HealthRecoverNum -= 250;
    }
    ~CrazyHostThrower(){}



private:

};

#endif

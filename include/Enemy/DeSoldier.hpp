#ifndef FAILING_SOLDIER_HPP
#define FAILING_SOLDIER_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class DeSoldier : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    DeSoldier() : Enemy("DeSoldier", 12, 17, 20, 13){
        //int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
        //, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
        //, bool Dizzy, bool Sleep, bool Frozen
        //, AttackType attack_t
        SetInfo(60000, 650, 600, 70, 4,
        2.5,2, 0.65, 0,
        false, false, false,
        CharacterAttackType::Physics);
        // Attack Range
        SetAttackRangeNum(2.5);
        SetAttackTimesBuff(2);
    }
    std::string GetName() override{
        return "DeSoldier";
    }
    void UpdateEffect() override {

    }
    ~DeSoldier(){}



private:
    int HPCounts = 1;
};

#endif // DeSoldier

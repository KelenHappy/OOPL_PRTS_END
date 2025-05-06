#ifndef BOSS_HPP
#define BOSS_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class BOSS : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    BOSS() : Enemy("BOSS", 30, 24, 40, 34){
        //int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
        //, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
        //, bool Dizzy, bool Sleep, bool Frozen
        //, AttackType attack_t
        SetInfo(40000, 1200, 1200, 30, 4,
        1,2, 0.65, 0,
        false, false, false,
        CharacterAttackType::Physics);
        // Attack Range
        SetAttackRangeNum(1);
        SetAttackTimesBuff(4);
    }
    std::string GetName() override{
        return "BOSS";
    }
    void UpdateEffect() override {

    }
    ~BOSS(){}



private:
    int HPCounts = 1;
};

#endif // BOSS

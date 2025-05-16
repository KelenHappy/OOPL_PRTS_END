#ifndef CRAZYHOSTLEADER_HPP
#define CRAZYHOSTLEADER_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class CrazyHostLeader : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    CrazyHostLeader() : Enemy("CrazyHostLeader", 20, 13, 57, 46){
        //int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
        //, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
        //, bool Dizzy, bool Sleep, bool Frozen
        //, AttackType attack_t
        SetInfo(30000*1.61*1.2, 1750*1.61, 230, 30, 1.3,
        1,1, 1.2, 2,
        false, false, false,
        CharacterAttackType::Physics);
        // Attack Range
        SetAttackRangeNum(1);
    }
    std::string GetName() override{
        return "CrazyHostLeader";
    }
    void UpdateEffect() override {
        HealthRecoverNum -= 500;
        I_Hpbar->Update(HealthRecoverNum,HealthNum);
    }
    ~CrazyHostLeader(){}



private:

};

#endif //CRAZYHOSTLEADER_HPP

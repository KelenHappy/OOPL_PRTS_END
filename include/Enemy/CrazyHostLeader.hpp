#ifndef CRAZYHOSTLEADER_HPP
#define CRAZYHOSTLEADER_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class CrazyHostLeader : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    CrazyHostLeader() : Enemy("CrazyHostLeader", 118, 77, 57, 118){
        //int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
        //, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
        //, bool Dizzy, bool Sleep, bool Frozen
        //, AttackType attack_t
        SetInfo(30000, 1750, 230, 30, 1.3,
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
    }
    ~CrazyHostLeader(){}



private:

};

#endif //CRAZYHOSTLEADER_HPP

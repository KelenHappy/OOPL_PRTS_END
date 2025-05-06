#ifndef CRAZYHOSTLEADER_HPP
#define CRAZYHOSTLEADER_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class KingStudent : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    KingStudent() : Enemy("KingStudent", 42, 20, 20, 13){
        //int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
        //, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
        //, bool Dizzy, bool Sleep, bool Frozen
        //, AttackType attack_t
        SetInfo(10000, 550, 700, 50, 2.5,
        1.3,1, 0.75, 0,
        false, false, false,
        CharacterAttackType::Physics);
        // Attack Range
        SetAttackRangeNum(1.3);
    }
    std::string GetName() override{
        return "KingStudent";
    }
    void UpdateEffect() override {
        if(HealthRecover <= 0 and HPCounts > 0){
            HPCounts -= 1;
            HealthRecover = HealthNum;
        }
    }
    ~KingStudent(){}



private:
    int HPCounts = 1;
};

#endif //KingStudent

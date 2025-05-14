#ifndef COLDBUG_HPP
#define COLDBUG_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class ColdBug : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    ColdBug() : Enemy("ColdBug", 57, 47, 25, 58){
        //int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
        //, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
        //, bool Dizzy, bool Sleep, bool Frozen
        //, AttackType attack_t
        SetInfo(3250, 300, 0, 0, 1.7,
        1, 1, 1.0, 0,
        false, false, false,
        CharacterAttackType::Physics);
    }
    std::string GetName() override{
        return "ColdBug";
    }

    void UpdateEffect() override {
        if (HealthRecoverNum <= 0) {

        }
    }
    ~ColdBug(){}



private:

};

#endif //COLDBUG_HPP

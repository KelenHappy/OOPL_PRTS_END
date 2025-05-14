#ifndef SNOWMANTEAM_HPP
#define SNOWMANTEAM_HPP
#include "Enemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
class SnowmanTeam : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    SnowmanTeam () : Enemy("SnowmanTeam", 59, 57, 57, 47){
        //int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
        //, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
        //, bool Dizzy, bool Sleep, bool Frozen
        //, AttackType attack_t
        SetInfo(3400, 360, 100, 0, 2.0,
        1, 1, 1.1, 1,
        false, false, false,
        CharacterAttackType::Physics);
        // Attack Range
        SetAttackRangeNum(1);
    }
    std::string GetName() override{
        return "SnowmanTeam";
    }
    ~SnowmanTeam(){}



private:

};

#endif //SNOWMANTEAM_HPP

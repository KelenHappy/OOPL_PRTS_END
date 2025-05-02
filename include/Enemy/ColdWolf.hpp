#ifndef COLDWOLF_HPP
#define COLDWOLF_HPP
class ColdWolf : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    ColdWolf() : Enemy("ColdWolf", 57, 59, 58, 30){
        //int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
        //, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
        //, bool Dizzy, bool Sleep, bool Frozen
        //, AttackType attack_t
        SetInfo(3150, 350, 0, 30, 1.4,
        1, 1, 1.9, 0,
        false, false, false,
        CharacterAttackType::Physics);
        // Attack Range
        SetAttackRangeNum(1);
    }
    std::string GetName() override{
        return "ColdWolf";
    }
    ~ColdWolf(){}


private:

};
#endif //COLDWOLF_HPP

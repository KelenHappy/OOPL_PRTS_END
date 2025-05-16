#ifndef IFRIT_HPP
#define IFRIT_HPP
#include "Character/Caster.hpp"
#include <vector>
class Ifrit : public Caster{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Ifrit() : Caster("Ifrit", 60, 77, 60, 58){
        /*
         *        void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
         *        int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
         *        HeavyLevel
         */
        SetInfo(70, 31, 2.9, 1680, 970, 130, 20,
                55, 80, 15, "攻擊力+20%，攻擊速度+80", "狂熱"
                , 1);

        //角色技能建立
        SetAttackBuff(1.2);
        SetAttackTimeBuff(0.8);


        //建立初始攻擊範圍
        this->m_DefaultRange.push_back({"2", "1", "1", "1", "1", "1"});

    }
    std::string GetChineseName() override {return "伊芙利特";}

    void OpenSkill() override{
        // Skill Func
        SkillOpen = true;
        SkillNow -= SkillCostNum;
        SkillTimeTemp = SkillTimeNum;
        // Skill Make
        AttackTimeNum *= AttackTimeBuff;
        AttackNum *= AttackBuff;
    }

    void CloseSkill() override{
        // Skill Func
        SkillOpen = false;
        SkillTimeNum = SkillTimeTemp;
        // Skill Make
        AttackTimeNum /= AttackTimeBuff;
        AttackNum /= AttackBuff;
    }

protected:
    int SkillTimeTemp = 0;
};
#endif //Ifrit_HPP

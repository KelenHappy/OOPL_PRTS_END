#ifndef HORN_HPP
#define HORN_HPP
#include "Character/Defender.hpp"
#include <vector>
class Horn : public Defender{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Horn() : Defender("Horn", 29, 73, 57, 58){
        /*
        void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
        int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
        HeavyLevel
        */
        SetInfo(70, 24, 2.8, 3067, 936, 620, 0,
        0, 40, 30, "攻擊力+70%，攻擊間隔大幅縮短（-1.8)", "終極防線"
        , 2);

        //角色技能建立
        SetAttackTimesBuff(1);
        SetAttackBuff(1.7);
        SetAttackTimeBuff(2.8);

        //建立初始攻擊範圍
        this->m_DefaultRange.push_back({"0", "0", "0", "1", "1"});
        this->m_DefaultRange.push_back({"2", "0", "0", "1", "1"});
        this->m_DefaultRange.push_back({"0", "0", "0", "1", "1"});

    }
    std::string GetChineseName() override {return "號角";}

    void OpenSkill() override{
        // Skill Func
        SkillOpen = true;
        SkillNow -= SkillCostNum;
        SkillTimeTemp = SkillTimeNum;
        // Skill Make
        AttackNum *= AttackBuff;
        AttackTimeNum /= AttackTimeBuff;
    }

    void CloseSkill() override{
        // Skill Func
        SkillOpen = false;
        SkillTimeNum = SkillTimeTemp;
        // Skill Make
        AttackNum /= AttackBuff;
        AttackTimeNum *= AttackTimeBuff;
    }

protected:
    int SkillTimeTemp = 0;
};
#endif //Horn_HPP

#ifndef CEOBE_HPP
#define CEOBE_HPP
#include "Character/Caster.hpp"
#include <vector>
class Ceobe : public Caster{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Ceobe() : Caster("Ceobe", 40, 48, 30, 59){
        /*
        void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
        int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
        HeavyLevel
        */
        SetInfo(70, 19, 1.6, 1565, 667, 128, 20,
        25, 40, 40, "攻擊間隔大幅縮短（*0.33。", "很熱的刀"
        , 1);

        //角色技能建立
        SetAttackTimeBuff(0.33);

        //建立初始攻擊範圍
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
        this->m_DefaultRange.push_back({"2", "1", "1", "1", "0"});
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});

    }
    std::string GetChineseName() override {return "刻俄柏";}

    void OpenSkill() override{
        // Skill Func
        SkillOpen = true;
        SkillNow -= SkillCostNum;
        SkillTimeTemp = SkillTimeNum;
        // Skill Make
        AttackTimeNum *= AttackTimeBuff;
    }

    void CloseSkill() override{
        // Skill Func
        SkillOpen = false;
        SkillTimeNum = SkillTimeTemp;
        // Skill Make
        AttackTimeNum /= AttackTimeBuff;

    }

protected:
    int SkillTimeTemp = 0;
};
#endif //CEOBE_HPP

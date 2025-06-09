#ifndef CUORA_HPP
#define CUORA_HPP
#include "Character/Defender.hpp"
#include <vector>
class Cuora : public Defender{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Cuora() : Defender("Cuora", 100, 60, 59, 59){
        /*
        void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
        int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
        HeavyLevel
        */
        SetInfo(70, 17, 1.2, 3105, 365, 690, 0,
        0, 40, 30, "停止攻擊敵人；體積數+1，防禦力+130%，每秒鐘恢復最大生命的3%", "殼狀防禦"
        , 3);

        //角色技能建立
        SetDefendBuff(1.3);

        //建立初始攻擊範圍

        this->m_DefaultRange.push_back({"2", "0", "0", "0", "0"});

    }
    std::string GetChineseName() override {return "蛇箱屠";}

    void OpenSkill() override{
        // Skill Func
        SkillOpen = true;
        SkillNow -= SkillCostNum;
        SkillTimeTemp = SkillTimeNum;
        // Skill Make
        DefendNum *= DefendBuff;
        SetAttackTimesBuff(0);
        HeavyLevelNum += 1;
    }

    void CloseSkill() override{
        // Skill Func
        SkillOpen = false;
        SkillTimeNum = SkillTimeTemp;
        // Skill Make
        DefendNum /= DefendBuff;
        SetAttackTimesBuff(1);
        HeavyLevelNum -= 1;

    }

protected:
    int SkillTimeTemp = 0;
};
#endif //CUORA_HPP

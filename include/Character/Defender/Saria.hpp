//
// Created by LAB1223 on 2025/5/9.
//

#ifndef SARIA_HPP
#define SARIA_HPP
#include "Character/Defender.hpp"
#include <vector>
class Saria : public Defender{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Saria() : Defender("Saria", 60, 70, 60, 50){
        /*
        void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
        int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
        HeavyLevel
        */
        SetInfo(70, 18, 1.2, 3150, 485, 595, 10,
        70, 80, 30, "附近所有友軍每秒回覆相當於塞雷婭攻擊力35%的生命附近所有敵軍受到的法術傷害+55%，移動速度-60%", "鈣質化"
        , 2);

        //角色技能建立
        SetDefendBuff(1.3);

        //建立初始攻擊範圍

        this->m_DefaultRange.push_back({"2", "0", "0", "0", "0"});

    }
    std::string GetChineseName() override {return "塞雷婭";}

    void OpenSkill() override{
        // Skill Func
        SkillOpen = true;
        SkillNow -= SkillCostNum;
        SkillTimeTemp = SkillTimeNum;
        // Skill Make

    }

    void CloseSkill() override{
        // Skill Func
        SkillOpen = false;
        SkillTimeNum = SkillTimeTemp;
        // Skill Make


    }

protected:
    int SkillTimeTemp = 0;
};
#endif //SARIA_HPP

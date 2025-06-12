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
    Saria() : Defender("Saria", 87, 70, 60, 50){
        /*
        void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
        int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
        HeavyLevel
        */
        SetInfo(70, 18, 1.2, 3150, 485, 595, 10,
        70, 80, 30, "附近所有友軍每秒回覆相當於塞雷婭攻擊力50%的生命", "鈣質化"
        , 2);

        //角色技能建立
        SetAttackBuff(0.5);
        SetAttackTimesBuff(1);
        //建立初始攻擊範圍

        this->m_DefaultRange.push_back({"2"});

    }
    std::string GetChineseName() override {return "塞雷婭";}

    void OpenSkill() override{
        // Skill Func
        SkillOpen = true;
        SkillNow -= SkillCostNum;
        SkillTimeTemp = SkillTimeNum;
        // Skill Make
        AttackType = CharacterAttackType::Health;
        AttackNum *= AttackBuff;
        m_DefaultRange.clear();
        this->m_DefaultRange.push_back({"0", "0", "0", "1", "0", "0", "0"});
        this->m_DefaultRange.push_back({"0", "0", "1", "1", "1", "0", "0"});
        this->m_DefaultRange.push_back({"0", "1", "1", "1", "1", "1", "0"});
        this->m_DefaultRange.push_back({"1", "1", "1", "2", "1", "1", "1"});
        this->m_DefaultRange.push_back({"0", "1", "1", "1", "1", "1", "0"});
        this->m_DefaultRange.push_back({"0", "0", "1", "1", "1", "0", "0"});
        this->m_DefaultRange.push_back({"0", "0", "0", "1", "0", "0", "0"});
    }

    void CloseSkill() override{
        if(GetSkillOpen()) {
            // Skill Func
            SkillOpen = false;
            SkillTimeNum = SkillTimeTemp;
            // Skill Make
            AttackNum /= AttackBuff;
            AttackType = CharacterAttackType::Physics;
            this->m_DefaultRange.clear();
            this->m_DefaultRange.push_back({"2", "0", "0", "0", "0"});
        }
    }

protected:
    int SkillTimeTemp = 0;
};
#endif //SARIA_HPP

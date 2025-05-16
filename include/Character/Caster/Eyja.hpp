#ifndef EYJA_HPP
#define EYJA_HPP
#include "Character/Caster.hpp"
#include <vector>
class Eyja : public Caster{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Eyja() : Caster("Eyja", 36, 37, 66, 70){
        /*
         *        void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
         *        int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
         *        HeavyLevel
         */
        SetInfo(70, 19, 1.6, 1743, 645, 122, 20,
                55, 80, 15, "攻擊力+130%，攻擊範圍增大，攻擊間隔大幅度縮短（-1.1），攻擊變為隨機對攻擊範圍內至多6個敵人發射熔岩", "火山"
                , 1);

        //角色技能建立
        SetAttackBuff(1.3);
        SetAttackTimeBuff(0.8);


        //建立初始攻擊範圍
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
        this->m_DefaultRange.push_back({"2", "1", "1", "1", "0"});
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});

    }
    std::string GetChineseName() override {return "艾雅法拉";}

    void OpenSkill() override{
        // Skill Func
        SkillOpen = true;
        SkillNow -= SkillCostNum;
        SkillTimeTemp = SkillTimeNum;
        // Skill Make
        AttackTimeNum *= AttackTimeBuff;
        AttackNum *= AttackBuff;
        SetAttackTimesBuff(6);

        m_DefaultRange.clear();
        this->m_DefaultRange.push_back({"0","0", "0", "1", "0", "0", "0"});
        this->m_DefaultRange.push_back({"0","0", "1", "1", "1", "0", "0"});
        this->m_DefaultRange.push_back({"0","1", "1", "1", "1", "1", "0"});
        this->m_DefaultRange.push_back({"1","1", "1", "2", "1", "1", "1"});
        this->m_DefaultRange.push_back({"0","1", "1", "1", "1", "1", "0"});
        this->m_DefaultRange.push_back({"0","0", "1", "1", "1", "0", "0"});
        this->m_DefaultRange.push_back({"0","0", "0", "1", "0", "0", "0"});
    }

    void CloseSkill() override{
        // Skill Func
        SkillOpen = false;
        SkillTimeNum = SkillTimeTemp;
        // Skill Make
        AttackTimeNum /= AttackTimeBuff;
        AttackNum /= AttackBuff;
        SetAttackTimesBuff(1);

        this->m_DefaultRange.clear();
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
        this->m_DefaultRange.push_back({"2", "1", "1", "1", "0"});
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
    }

protected:
    int SkillTimeTemp = 0;
};
#endif //Eyja_HPP

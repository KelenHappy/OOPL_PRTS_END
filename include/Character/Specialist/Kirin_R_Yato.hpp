//
// Created by LAB1223 on 2025/5/23.
//

#ifndef KIRIN_R_YATO_HPP
#define KIRIN_R_YATO_HPP
class KirinRYato : public Specialist{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    KirinRYato() : Specialist("Kirin_R_Yato", 50, 60, 58, 58){
        /*
         void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
         int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
         HeavyLevel
         */
        SetInfo(18, 8, 0.93, 1629, 565, 318, 0,
        0, -1, 2, "第一天賦效果提升至2.5倍，攻擊力提升至150%並對前方一格的所有敵人發動16次斬擊，期間更容易受到敵人的攻擊", "空中迴旋亂舞"
        , 1);
        //角色技能建立
        SetAttackBuff(2.2);

        //建立初始攻擊
        this->m_DefaultRange.push_back({"2", "1", "0", "0"});
    }
    std::string GetChineseName() override {return "麒麟R夜刀";}
    void OpenSkill() override{
        // Skill Func
        SkillOpen = true;
        SkillNow -= SkillCostNum;
        SkillTimeTemp = SkillTimeNum;
        // Skill Make
        AttackNum *= AttackBuff;
        mod=0;

    }

    void CloseSkill() override{
        if (GetSkillOpen()and mod==0) {
            mod=1;
            AttackNum /= 2;
            SetType(CharacterAttackType::Magic);
        }
        if(GetSkillOpen()) {
            // Skill Func
            SkillOpen = false;
            SkillTimeNum = SkillTimeTemp;
            // Skill Make
            AttackNum /= AttackBuff/2;
            SetType(CharacterAttackType::Physics);
        }
    }

protected:
    int SkillTimeTemp = 0;
    int mod=0;
};

#endif //KIRIN_R_YATO_HPP

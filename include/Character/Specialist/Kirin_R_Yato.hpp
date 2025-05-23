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
        0, -1, 8, "向前突進2格，每突進一段距離都會對周圍所有敵人發動攻擊力300%的斬擊；期間每攻擊到一個敵人都會使突進距離延長（最多延長至5格，可以攻擊空中單位）", "空中迴旋亂舞"
        , 0);
        //角色技能建立
        SetAttackBuff(3);

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


    }

    void CloseSkill() override{
        // Skill Func
        SkillOpen = false;
        SkillTimeNum = SkillTimeTemp;
        // Skill Make
        AttackNum /= AttackBuff;
    }

protected:
    int SkillTimeTemp = 0;
};

#endif //KIRIN_R_YATO_HPP

#ifndef TEXAS_THE_OMERTOSA_HPP
#define TEXAS_THE_OMERTOSA_HPP
#include "Character/Specialist.hpp"
#include <vector>
class TexasTheOmertosa : public Specialist{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    TexasTheOmertosa() : Specialist("Texas_the_Omertosa", 60, 56, 60, 59){
        /*
         void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
         int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
         HeavyLevel
         */
		SetInfo(18, 8, 0.93, 1598, 569, 320, 0,
		0, -1, 8, "部署後立即對周圍敵人造成兩次相當於攻擊力165%的法術傷害並使目標暈眩2秒，造成攻擊力130%的法術傷害和暈眩", "劍雨滂沱"
		, 0);
		//角色技能建立
		SetAttackBuff(2.65);
    	SetAttackImpact(CharacterAttackImpact::Dizzy);
    	SetAttackType(CharacterAttackType::Magic);

		//建立初始攻擊
		this->m_DefaultRange.push_back({"2", "1", "0", "0"});
    }
	std::string GetChineseName() override {return "緘默德克薩斯";}
		void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		SetAttackTimesBuff(4);
		AttackNum *= AttackBuff;
        AttackImpact = CharacterAttackImpact::Dizzy;

        this->m_DefaultRange.clear();
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
        this->m_DefaultRange.push_back({"1", "2", "1", "0", "1"});
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});

	}

	void CloseSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillTimeNum = SkillTimeTemp;
		// Skill Make
		SetAttackTimesBuff(1);
		AttackNum /= AttackBuff;
        AttackImpact = CharacterAttackImpact::Null;

        this->m_DefaultRange.clear();
		this->m_DefaultRange.push_back({"2", "1", "0", "0"});
	}

protected:
	int SkillTimeTemp = 0;
};

#endif //TEXAS_THE_OMERTOSA_HPP

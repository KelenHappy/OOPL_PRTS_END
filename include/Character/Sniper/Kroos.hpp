//Kroos
#ifndef KROOS_HPP
#define KROOS_HPP
#include "Character/Sniper.hpp"
#include <vector>
class Kroos : public Sniper{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Kroos() : Sniper("Kroos", 118, 54, 58, 48){
        /*
         void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
         int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
         HeavyLevel
         */
		SetInfo(70, 9, 1, 1060, 375, 126, 0,
		0, 4, 0, "下次攻擊时連續攻擊2次，每次及造成相當於攻擊力140%的物理傷害", "二連射·自動"
		, 1);
		//角色技能建立
		SetAttackBuff(1.4);
		//建立初始攻擊範圍
		SetAttackRangeNum(4);
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"2", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    }
	
	std::string GetChineseName() override {return "克洛里斯";}
	
	void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		AttackNum *= AttackBuff;
        SetAttackTimesBuff(2);
	}

	void CloseSkill() override{
		// Skill Func
		SkillOpen = false;
		SkillTimeNum = SkillTimeTemp;
		// Skill Make
		AttackNum /= AttackBuff;
        SetAttackTimesBuff(1);
	}

protected:
	int SkillTimeTemp = 0;
};

#endif

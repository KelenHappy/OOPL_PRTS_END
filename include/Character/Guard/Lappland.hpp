#ifndef LAPPLAND_HPP
#define LAPPLAND_HPP
#include "Character/Guard.hpp"
#include <vector>
class Lappland : public Guard{
public:
//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Lappland() : Guard("Lappland", 29, 65, 58, 48){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		HeavyLevel
		*/
		SetInfo(70, 17, 1.3, 2350, 685, 363, 15,
		0, 17, 20, "攻擊力+120%，傷害類型提高作用，額外攻擊一個目標，遠程攻擊不再降低攻擊力", "狼魂"
		, 2);

		//角色技能建立
    	SetAttackBuff(1.2);
		//建立初始攻擊範圍

		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    	this->m_DefaultRange.push_back({"1", "1", "0", "0", "0"});
		this->m_DefaultRange.push_back({"2", "1", "1", "1", "1"});
    	this->m_DefaultRange.push_back({"1", "1", "0", "0", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    }
	std::string GetChineseName() override {return "拉普蘭德";}

	void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
    	SetAttackType(CharacterAttackType::Magic);
    	AttackNum *= AttackBuff;
	}

	void CloseSkill() override{
		// Skill Func
		SkillOpen = false;
		SkillTimeNum = SkillTimeTemp;
		// Skill Make
    	SetAttackType(CharacterAttackType::Physics);
    	AttackNum /= AttackBuff;


	}

protected:
	int SkillTimeTemp = 0;
};
#endif //LAPPLAND_HPP

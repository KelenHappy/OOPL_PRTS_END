//Ines
#ifndef INES_HPP
#define INES_HPP
#include "Character/Vanguard.hpp"
#include <vector>
class Ines : public Vanguard{
public:
//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Ines() : Vanguard("Ines", 60, 58, 59, 59){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		HeavyLevel
		*/
		SetInfo(35, 9, 1, 2121, 589, 281, 0,
		15, 20, 12, "攻擊範圍擴大，攻擊力+110%", "暗夜無明"
		, 1);
		//角色技能建立
		SetAttackBuff(2.1);
		SetAttackRangeNumBuff(1);
		SetAttackTimeBuff(0.9);
		//建立初始攻擊範圍
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"2", "1", "1", "0", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    }
	std::string GetChineseName() override {return "伊內絲";}

	void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		AttackNum *= AttackBuff;
		AttackTimeNum *= AttackTimeBuff;
		this->m_DefaultRange.clear();
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"0", "1", "1", "0", "0"});
		this->m_DefaultRange.push_back({"2", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"0", "1", "1", "0", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
	}

	void CloseSkill() override{
		// Skill Func
		SkillOpen = false;
		SkillTimeNum = SkillTimeTemp;
		// Skill Make
		AttackNum /= AttackBuff;
		AttackTimeNum /= AttackTimeBuff;
		this->m_DefaultRange.clear();
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"2", "1", "1", "0", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
	}

protected:
	int SkillTimeTemp = 0;
};

#endif

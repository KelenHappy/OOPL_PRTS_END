//Myrtle
#ifndef MYRTLE_HPP
#define MYRTLE_HPP
#include "Character/Vanguard.hpp"
#include <vector>
class Myrtle : public Vanguard{
public:
//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Myrtle() : Vanguard("Myrtle", 50, 26, 59, 60){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		HeavyLevel
		*/
		SetInfo(70, 8, 1.3, 1565, 520, 300, 0,
		10, 24, 16, "停止攻擊，並每秒治療周圍一名友方單位，相當桃金娘攻擊力50%的生命", "治癒之翼"
		, 1);
		//角色技能建立
		SetAttackBuff(-0.5);
		SetType(CharacterAttackType::Health);
		//建立初始攻擊範圍
		SetAttackRangeNum(2);
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"2", "1", "0", "0", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    }
	std::string GetChineseName() override {return "桃金娘";}

	void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		AttackNum *= AttackBuff;
		AttackType = TypeBuff;
		this->m_DefaultRange.clear();
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"0", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"0", "1", "2", "1", "0"});
		this->m_DefaultRange.push_back({"0", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
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
    		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    		this->m_DefaultRange.push_back({"2", "1", "0", "0", "0"});
    		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    	}

	}

protected:
	int SkillTimeTemp = 0;
};

#endif

//Exudiai
#ifndef EXUDIAI_HPP
#define EXUDIAI_HPP
#include "Character/Sniper.hpp"
#include <vector>
class Exusiai : public Sniper{
public:
    Exusiai() : Sniper("Exusiai", 60, 61, 60, 60){
		SetInfo(70, 12, 1, 1673, 540, 161, 0,
		20, 30, 15, "攻擊變為5連射，攻擊間隔一定程度縮短(-0.22)", "過載模式"
		, 1);
		//角色技能建立
		SetAttackTimeBuff((GetAttackTime()-0.22)/GetAttackTime());
		//建立初始攻擊範圍
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"2", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    }
	std::string GetChineseName() override {return "能天使";}
		void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		AttackTimess = 5;
		AttackTimeNum *= AttackTimeBuff;
	}
	
	void CloseSkill() override{
    	if(GetSkillOpen()) {
    		// Skill Func
    		SkillOpen = false;
    		SkillTimeNum = SkillTimeTemp;
    		// Skill Make
    		AttackTimess = 1;
    		AttackTimeNum /= AttackTimeBuff;
    	}
	}

protected:
	int SkillTimeTemp = 0;
};

#endif

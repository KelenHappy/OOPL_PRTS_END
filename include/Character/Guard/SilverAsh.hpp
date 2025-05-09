#ifndef SILVERASH_HPP
#define SILVERASH_HPP
#include "Character/Guard.hpp"
#include <vector>
class SilverAsh : public Guard{
public:
//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    SilverAsh() : Guard("SilverAsh", 30, 80, 60, 61){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		HeavyLevel
		*/
		SetInfo(70, 18, 1.3, 2560, 713, 397, 10,
		75, 90, 30, "防禦力-70%，攻擊力+200%，攻擊範圍擴大，同時攻擊至多6個目標", "真銀斬"
		, 2);

		//角色技能建立
    	SetAttackTimesBuff(1);
		//建立初始攻擊範圍
    	SetAttackBuff(3);
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"1", "1", "0", "0", "0"});
		this->m_DefaultRange.push_back({"2", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"1", "1", "0", "0", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    }
	std::string GetChineseName() override {return "銀灰";}

	void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		SetAttackTimesBuff(6);
    	AttackNum *= AttackBuff;
    	DefendNum *= DefendBuff;

		this->m_DefaultRange.clear();
    	this->m_DefaultRange.push_back({"1", "0", "0", "0", "0"});
    	this->m_DefaultRange.push_back({"1", "1", "0", "0", "0"});
    	this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
    	this->m_DefaultRange.push_back({"2", "1", "1", "1", "0"});
    	this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
    	this->m_DefaultRange.push_back({"1", "1", "0", "0", "0"});
    	this->m_DefaultRange.push_back({"1", "0", "0", "0", "0"});
	}

	void CloseSkill() override{
		// Skill Func
		SkillOpen = false;
		SkillTimeNum = SkillTimeTemp;
		// Skill Make
		SetAttackTimesBuff(1);
    	AttackNum /= AttackBuff;
    	DefendNum /= DefendBuff;

		this->m_DefaultRange.clear();
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"1", "0", "0", "0", "0"});
		this->m_DefaultRange.push_back({"2", "1", "0", "0", "0"});
		this->m_DefaultRange.push_back({"1", "0", "0", "0", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));

	}

protected:
	int SkillTimeTemp = 0;
};


#endif //SILVERASH_HPP

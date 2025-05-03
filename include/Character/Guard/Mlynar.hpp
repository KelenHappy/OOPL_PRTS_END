//Mlynar
#ifndef MLYNAR_HPP
#define MLYNAR_HPP
#include "Character/Guard.hpp"
#include <vector>
class Mlynar : public Guard{
public:
//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Mlynar() : Guard("Mlynar", 118, 70, 57, 58){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		HeavyLevel
		*/
		SetInfo(70, 10, 1.2, 3906, 355, 502, 15,
		10, 25, 20, "攻擊範圍擴大，攻擊力+110%", "未寬解的悲哀"
		, 2);
		//角色技能建立
        SetAttackTimesBuff(0);
		SetAttackRangeNumBuff(1);
		//建立初始攻擊範圍
		SetAttackRangeNum(2);

		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"2", "1", "1", "0", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    }
	std::string GetChineseName() override {return "瑪恩納";}

	void OpenSkill() override{
		SkillOpen = true;
		AttackNum *= AttackBuff;
		AttackRangeNum += AttackRangeNumBuff;
	}

	void CloseSkill() override{
		SkillOpen = false;
		AttackNum /= AttackBuff;
		AttackRangeNum -= AttackRangeNumBuff;
	}

protected:

};

#endif

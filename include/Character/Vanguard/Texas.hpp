//Texas
#ifndef TEXAS_HPP
#define TEXAS_HPP
#include "Character/Vanguard.hpp"
#include <vector>
class Texas : public Vanguard{
public:
    Texas() : Vanguard("Texas", 120, 60, 60, 61){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		HeavyLevel
		*/
		//1950
		SetInfo(70, 11, 1.05, 1950, 500, 343, 0,
		30, 40, 0, "立即獲得12點費用；對周圍所有敵人造成兩次相當於攻擊力170%的法術傷害，並擊中目標暈眩3秒", "劍雨"
		, 2);
		//角色技能建立
		SetImpact(CharacterAttackImpact::Dizzy);
		SetType(CharacterAttackType::Magic);
		SetAttackBuff(1.7);
		//建立初始攻擊範圍
		SetAttackRangeNum(2);
		SetDefaultRange();
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange->push_back({"2", "1", "0", "0", "0"});
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
    }
	std::string GetChineseName() override {return "德克薩斯";}

	
	void OpenSkill() override{
		SkillOpen = true;
		AttackImpact =  ImpactBuff;
		AttackType = TypeBuff;
		AttackNum *= AttackBuff;
	}
	
	void CloseSkill() override{
		SkillOpen = false;
		AttackImpact =  CharacterAttackImpact::Null;
		AttackType = CharacterAttackType::Physics;
		AttackNum /= AttackBuff;
	}

protected:

};

#endif

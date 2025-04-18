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
		SetInfo(35, 11, 1, 2121, 589, 281, 0,
		15, 20, 12, "立即獲得12點費用；對周圍所有敵人造成兩次相當於攻擊力170%的法術傷害，並擊中目標暈眩3秒", "劍雨"
		, 1);
		//角色技能建立
		SetImpact(CharacterAttackImpact::Dizzy);
		SetAttackBuff(1.7);
		//建立初始攻擊範圍
		SetAttackRangeNum(3);
		SetDefaultRange();
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange->push_back({"2", "1", "1", "0", "0"});
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
    }

protected:

};

#endif

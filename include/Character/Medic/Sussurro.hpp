//Sussurro
#ifndef SUSSURRO_HPP
#define SUSSURRO_HPP
#include "Character/Medic.hpp"
#include <vector>
class Sussurro : public Medic{
public:
    Sussurro() : Medic("Sussurro", 119, 61, 60, 61){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		HeavyLevel
		*/
		SetInfo(70, 18, 2.85, 1345, -488, 122, 0,
		10, 30, 25, "攻擊力+100%，攻擊速度+100同一次作戰中", "深度治療"
		, 1);
		//角色技能建立
		SetAttackBuff(2);
		SetAttackTimeBuff(1+100/GetAttackTime());
		//建立初始攻擊範圍
		SetAttackType(CharacterAttackType::Health);
		SetAttackRangeNum(4);
		SetDefaultRange();
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange->push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange->push_back({"2", "1", "1", "1", "0"});
		this->m_DefaultRange->push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
    }

protected:

};

#endif

#ifndef GNOSIS_HPP
#define GNOSIS_HPP
#include "Character/Supporter.hpp"
#include <vector>
class Gnosis : public Supporter{
public:
	//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Gnosis() : Supporter("Gnosis", 60, 76, 60, 59){
    	/*
		 void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		 int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		 HeavyLevel
		 */
		SetInfo(70, 11, 1.6, 2035, 455, 132, 25,
		25, 40, 13, "攻擊速度+130，同時攻擊2個敵人；範圍內敵人的凍結延長至技能結束，且技能結束時對所有凍結的敵人造成600%的法術傷害並結束凍結；優先攻擊未凍結的單位", "失溫症"
		, 1);
		SetAttackImpact(CharacterAttackImpact::Frozen);
    	SetAttackType(CharacterAttackType::Magic);
    	//角色技能建立
    	SetAttackTimeBuff(0.43);
		SetAttackBuff(6);
		//建立初始攻擊範圍
		SetAttackRangeNum(4);
		this->m_DefaultRange.push_back({"0", "1", "1", "0", "0"});
		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"1", "2", "1", "1", "0"});
		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"0", "1", "1", "0", "0"});
    }
	std::string GetChineseName() override {return "靈知";}

	void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		AttackTimeNum *= AttackTimeBuff;
    	AttackNum *= AttackBuff;
    	AttackTimes = 2;

    	this->m_DefaultRange.clear();
    	this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
    	this->m_DefaultRange.push_back({"1", "1", "1", "1", "1"});
    	this->m_DefaultRange.push_back({"1", "2", "1", "1", "1"});
    	this->m_DefaultRange.push_back({"1", "1", "1", "1", "1"});
    	this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});

	}

	void CloseSkill() override{
		// Skill Func
		SkillOpen = false;
		SkillTimeNum = SkillTimeTemp;
		// Skill Make
		AttackTimeNum /= AttackTimeBuff;
    	AttackNum /= AttackBuff;
    	AttackTimes = 1;

    	this->m_DefaultRange.clear();
    	this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
    	this->m_DefaultRange.push_back({"1", "2", "1", "1", "0"});
    	this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
	}

protected:
	int SkillTimeTemp = 0;
};

#endif //GNOSIS_HPP

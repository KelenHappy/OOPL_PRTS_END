//Suzuran
#ifndef SUZURAN_HPP
#define SUZURAN_HPP
#include "Character/Supporter.hpp"
#include <vector>
class Suzuran : public Supporter{
public:
	//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Suzuran() : Supporter("Suzuran", 54, 43, 28, 61){
    	/*
		 void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		 int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		 HeavyLevel
		 */
		SetInfo(70, 14, 1.9, 1480, 521, 128, 25,
		50, 70, 35, "停止攻擊，攻擊範圍擴大，攻擊範圍內的敵人被停頓，且每秒回復範圍內所有友方單位相當於攻擊力20%的生命", "狐火渺然"
		, 1);
		SetAttackImpact(CharacterAttackImpact::Dizzy);
    	SetAttackType(CharacterAttackType::Magic);
    	//角色技能建立
		SetAttackBuff(0.1);
		//建立初始攻擊範圍
		SetAttackRangeNum(4);
		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"1", "2", "1", "1", "0"});
		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
    }
	std::string GetChineseName() override {return "鈴蘭";}
		void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		AttackTimeNum *= AttackTimeBuff;
    	AttackTimes = 5;

    	this->m_DefaultRange.clear();
    	this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
    	this->m_DefaultRange.push_back({"1", "1", "1", "1", "1"});
    	this->m_DefaultRange.push_back({"1", "2", "1", "1", "1"});
    	this->m_DefaultRange.push_back({"1", "1", "1", "1", "1"});
    	this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});

	}

	void CloseSkill() override{
    	if(GetSkillOpen()) {
    		// Skill Func
    		SkillOpen = false;
    		SkillTimeNum = SkillTimeTemp;
    		// Skill Make
    		AttackTimeNum /= AttackTimeBuff;
    		AttackTimes = 1;

    		this->m_DefaultRange.clear();
    		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
    		this->m_DefaultRange.push_back({"1", "2", "1", "1", "0"});
    		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
    	}
	}

protected:
	int SkillTimeTemp = 0;
};

#endif //Suzuran

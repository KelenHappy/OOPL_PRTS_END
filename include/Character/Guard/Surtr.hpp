#ifndef SURTR_HPP
#define SURTR_HPP
#include "Character/Guard.hpp"
#include <vector>
class Surtr : public Guard{
public:
//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Surtr() : Guard("Surtr", 40, 77, 26, 60){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		HeavyLevel
		*/
		SetInfo(70, 19, 1.25, 2916, 672, 414, 15,
		0, 5, 99, "立即恢復所有生命；攻擊力+330%，攻擊距離+2，攻擊目標數+3，上限+5000，逐漸失去生命（60秒後到達最大生命生命20%/秒）；持續時間無限", "黄昏"
		, 1);
    	AttackType = CharacterAttackType::Magic;
		//角色技能建立
    	SetAttackTimesBuff(1);
    	SetAttackBuff(3.3);
    	SetHealthBuff(5000);
		//建立初始攻擊範圍

		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    	this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"2", "1", "0", "0", "0"});
    	this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    }
	std::string GetChineseName() override {return "史爾特爾";}
	void UpdateEffect() override {
    	if (GetState() != CharacterState::Default
    		and SkillOpen)HealthRecoverNum -= HealthNum*0.2;
    }
	void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		SetAttackTimesBuff(3);
    	AttackNum *= AttackBuff;
		HealthRecoverNum += HealthRecoverBuff;

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


#endif //SURTR_HPP

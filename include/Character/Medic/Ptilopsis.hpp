//Ptilopsis
#ifndef PTILOPSIS_HPP
#define PTILOPSIS_HPP
#include "Character/Medic.hpp"
#include <vector>
class Ptilopsis : public Medic{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Ptilopsis() : Medic("Ptilopsis", 30, 70, 58, 59){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		HeavyLevel
		*/
		SetInfo(70, 15, 2.85, 1610, -335, 150, 0,
		85, 100, 40, "攻擊力+100%，攻擊速度+100同一次作戰中", "腦啡肽"
		, 1);
		//角色技能建立
		SetAttackRangeNum(1);
		SetAttackTimeBuff(1.85/GetAttackTime());
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
	
	std::string GetChineseName() override {return "白面鴞";}
	
	void OpenSkill() override{
		SkillOpen = true;
		AttackRangeNum +=  AttackRangeNumBuff;
		AttackTimeNum *= AttackTimeBuff;
	}

	void CloseSkill() override{
		SkillOpen = false;
		AttackRangeNum -=  AttackRangeNumBuff;
		AttackTimeNum /= AttackTimeBuff;
	}

protected:

};

#endif

//Exudiai
#ifndef MIZUKI_HPP
#define MIZUKI_HPP
#include "Character/Specialist.hpp"
#include <vector>
class Mizuki : public Specialist{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Mizuki() : Specialist("Mizuki", 107, 29, 58, 59){
        /*
         void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
         int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
         HeavyLevel
         */
		SetInfo(70, 19, 3.5, 1758, 865, 356, 30,
		30, 60, 30, "攻擊範圍擴大，攻擊力+150%，第一天賦額外攻擊2個目標並附加1秒暈眩", "鏡花水月"
		, 0);
		//角色技能建立
		SetAttackBuff(2.5);

		//建立初始攻擊範圍
		SetAttackRangeNum(4);
		this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
		this->m_DefaultRange.push_back({"1", "2", "1", "1", "0"});
		this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
    }
	std::string GetChineseName() override {return "水月";}
		void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		SetAttackTimesBuff(AttackTimes+2);
		AttackNum *= AttackBuff;
        AttackImpact = CharacterAttackImpact::Dizzy;

        this->m_DefaultRange.clear();
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
        this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
        this->m_DefaultRange.push_back({"1", "2", "1", "1", "1"});
        this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});

	}

	void CloseSkill() override{
		// Skill Func
		SkillOpen = false;
		SkillTimeNum = SkillTimeTemp;
		// Skill Make
		SetAttackTimesBuff(AttackTimes-2);
		AttackNum /= AttackBuff;
        AttackImpact = CharacterAttackImpact::Null;

        this->m_DefaultRange.clear();
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
        this->m_DefaultRange.push_back({"1", "2", "1", "1", "0"});
        this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
	}

protected:
	int SkillTimeTemp = 0;
};

#endif

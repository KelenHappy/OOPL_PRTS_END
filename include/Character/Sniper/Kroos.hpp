//Kroos
#ifndef KROOS_HPP
#define KROOS_HPP
#include "Character/Sniper.hpp"
#include <vector>
class Kroos : public Sniper{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Kroos() : Sniper("Kroos", 118, 54, 58, 48){
        /*
         void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
         int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
         HeavyLevel
         */
		SetInfo(70, 9, 1, 1060, 375, 126, 0,
		0, 4, 0, "7 	下次攻擊时連續及2次，每次及造成相當於攻擊力140%的物理傷害", "二連射·自動"
		, 1);
		//角色技能建立
		SetAttackBuff(5);
		SetAttackTimeBuff((GetAttackTime()-0.22)/GetAttackTime());
		//建立初始攻擊範圍
		SetAttackRangeNum(4);
		SetDefaultRange();
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange->push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange->push_back({"2", "1", "1", "1", "0"});
		this->m_DefaultRange->push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
    }

	void OpenSkill() override{
		SkillOpen = true;
		AttackNum *= AttackBuff;
		AttackTimeNum *= AttackTimeBuff;
	}

	void CloseSkill() override{
		SkillOpen = false;
		AttackNum /= AttackBuff;
		AttackTimeNum /= AttackTimeBuff;
	}

protected:

};

#endif

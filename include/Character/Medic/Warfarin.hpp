//Warfarin
#ifndef WARFARIN_HPP
#define WARFARIN_HPP
#include "Character/Medic.hpp"
#include <vector>
class Warfarin : public Medic{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Warfarin() : Medic("Warfarin", 119, 69, 59, 60){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string 	skillinfo, std::string skillname,
		HeavyLevel
		*/
		SetInfo(70, 17, 2.85, 1520, -505, 125, 0,
                50, 60, 15, "自身和攻擊範圍内隨機一名我方單位獲得以下狀態：攻擊力+90%，每秒流失3%最大生命值，持續15秒", "不穩定血漿"
		, 1);
		//角色技能建立
		SetAttackBuff(1.9);

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

	void OpenSkill() override{
		SkillOpen = true;
		AttackNum *=  AttackBuff;

	}

	void CloseSkill() override{
		SkillOpen = false;
		AttackNum /=  AttackBuff;

	}

protected:

};

#endif

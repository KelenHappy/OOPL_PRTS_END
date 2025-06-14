//Warfarin
#ifndef WARFARIN_HPP
#define WARFARIN_HPP
#include "Character/Medic.hpp"
#include <vector>
class Warfarin : public Medic{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Warfarin() : Medic("Warfarin", 30, 69, 59, 60){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string 	skillinfo, std::string skillname,
		HeavyLevel
		*/
		SetInfo(70, 17, 2.85, 1520, -505, 125, 0,
                50, 60, 15, "自身和攻擊範圍内隨機一名我方單位獲得以下狀態：攻擊力+90%，流失15%最大生命值，持續15秒", "不穩定血漿"
		, 1);
		//角色技能建立
		SetAttackTimesBuff(3);
		SetAttackBuff(1.9);
		SetInfoForBuffU(1.9,1,1, 0.85);
		//建立初始攻擊範圍
		SetAttackType(CharacterAttackType::Health);
		SetAttackRangeNum(4);
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"2", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    }

	std::string GetChineseName() override {return "華法琳";}
	void BuffU(std::shared_ptr<AnimatedCharacter> getBuff) override{
		if (getBuff) {
			getBuff->SetGetBuff(true);
			getBuff->SetBuffTime(15);
			(getBuff)->ApplyBuff(AttackBB, DefendBB, AttackSpeedBB, HPBB);
		}
	}
	
	void OpenSkill() override{
    	if(GetSkillOpen()) {
    		// Skill Func
    		SkillOpen = true;
    		SkillNow -= SkillCostNum;
    		SkillTimeTemp = SkillTimeNum;
    		// Skill Make
    		AttackNum *=  AttackBuff;
    	}

	}

	void CloseSkill() override{
		// Skill Func
		SkillOpen = false;
		SkillTimeNum = SkillTimeTemp;
		// Skill Make
		AttackNum /=  AttackBuff;

	}

protected:
	int SkillTimeTemp = 0;
};

#endif

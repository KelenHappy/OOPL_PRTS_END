//Mlynar
#ifndef MLYNAR_HPP
#define MLYNAR_HPP
#include "Character/Guard.hpp"
#include <vector>
class Mlynar : public Guard{
public:
//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Mlynar() : Guard("Mlynar", 118, 70, 57, 58){
		/*
		void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
		int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
		HeavyLevel
		*/
		SetInfo(70, 10, 1.2, 3906, 355*1.2, 502, 15,
		20, 42, 28, "攻擊範圍擴大，特性提升至2倍（每擊倒一名敵人時特性倍率-10%），攻擊對5個目標造成相當於180%攻擊力的物理傷害。 範圍內所有敵人受到卡西米爾幹員攻擊時額外附帶瑪恩納12%攻擊力的真實傷害", "未照耀的荣光"
		, 0);
		//角色技能建立
        SetAttackTimesBuff(0);
        SetAttackBuff(2.8);
        SetDefendBuff(1.25);
		//建立初始攻擊範圍

		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
		this->m_DefaultRange.push_back({"1", "0", "0", "0", "0"});
		this->m_DefaultRange.push_back({"2", "1", "0", "0", "0"});
		this->m_DefaultRange.push_back({"1", "0", "0", "0", "0"});
		this->m_DefaultRange.push_back(std::vector<std::string>(5, "0"));
    }
	std::string GetChineseName() override {return "瑪恩納";}
	void UpdateEffect() override{
    	if(AttackNum<355*1.25)AttackNum += (355*0.05);
	}
	void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		HeavyLevelNum = 3;
		AttackNum *= AttackBuff;
		SetAttackTimesBuff(5);
		DefendNum *= DefendBuff;
		this->m_DefaultRange.clear();
		this->m_DefaultRange.push_back({"1", "1", "0", "0", "0"});
		this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
		this->m_DefaultRange.push_back({"2", "1", "1", "1", "0"});
		this->m_DefaultRange.push_back({"1", "1", "1", "0", "0"});
		this->m_DefaultRange.push_back({"1", "1", "0", "0", "0"});

	}

	void CloseSkill() override{
    	if(GetSkillOpen()) {
    		// Skill Func
    		SkillOpen = false;
    		SkillTimeNum = SkillTimeTemp;
    		m_Drawable = m_IdleAnimation;
    		// Skill Make
    		AttackNum=355;
    		HeavyLevelNum = 0;
    		AttackNum /= AttackBuff;
    		SetAttackTimesBuff(0);
    		DefendNum /= DefendBuff;
    		this->m_DefaultRange.clear();
    		this->m_DefaultRange.push_back({"1", "0", "0", "0", "0"});
    		this->m_DefaultRange.push_back({"2", "1", "0", "0", "0"});
    		this->m_DefaultRange.push_back({"1", "0", "0", "0", "0"});
    	}

	}

protected:
	int SkillTimeTemp = 0;
};

#endif

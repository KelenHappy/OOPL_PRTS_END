//
// Created by LAB1223 on 2025/5/23.
//

#ifndef GRAVEL_HPP
#define GRAVEL_HPP
#include "Character/Specialist.hpp"
#include <vector>
class Gravel : public Specialist{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    Gravel() : Specialist("Gravel", 39, 60, 59, 59){
        /*
         void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
         int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
         HeavyLevel
         */
		SetInfo(18, 6, 0.93, 1420, 335, 356, 0,
		0, 0, 10, "部署後獲得可吸收相當於自己最大生命250%的屏障", "鼠群"
		, 1);
		//角色技能建立
    	 SetHealthBuff(3);
		//建立初始攻擊範圍
		this->m_DefaultRange.push_back({"0", "2", "1", "0", "0"});
    }
	std::string GetChineseName() override {return "礫";}
		void OpenSkill() override{
		// Skill Func
		SkillOpen = true;
		SkillNow -= SkillCostNum;
		SkillTimeTemp = SkillTimeNum;
		// Skill Make
		HealthRecoverNum *= HealthBuff;
    	Bully = HealthRecoverNum*2;

	}

	void CloseSkill() override{
    	if(GetSkillOpen()) {
    		// Skill Func
    		SkillOpen = false;
    		SkillTimeNum = SkillTimeTemp;
    		// Skill Make
    	}
	}

protected:
	int Bully = 0;
	int SkillTimeTemp = 0;
};
#endif //GRAVEL_HPP

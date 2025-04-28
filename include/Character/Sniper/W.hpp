//W
#ifndef W_HPP
#define W_HPP
#include "Character/Sniper.hpp"
#include <vector>
class W : public Sniper{
public:
    //std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
    W() : Sniper("W", 120, 125, 58, 58){
        /*
         void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
         int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
         HeavyLevel
         */
		SetInfo(70, 23, 2.1, 1888, 687, 256, 15,
                40, 50, 0, "攻擊+180%，攻擊間隔大幅增大(+2.9)，攻擊時攻擊力提升至220%", "爆裂黎明"
		, 1);
		//角色技能建立
		SetAttackBuff(2.8);
        SetAttackRangeNum(3);
		//建立初始攻擊範圍
		SetAttackRangeNum(4);
		SetDefaultRange();
		this->m_DefaultRange->push_back({"1", "1", "1", "0", "0"});
		this->m_DefaultRange->push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange->push_back({"2", "1", "1", "1", "1"});
		this->m_DefaultRange->push_back({"1", "1", "1", "1", "0"});
		this->m_DefaultRange->push_back({"1", "1", "1", "0", "0"});
    }
	
	std::string GetChineseName() override {return "維什戴爾";}
	
	void OpenSkill() override{
		SkillOpen = true;
		AttackNum *= AttackBuff;
        AttackRangeNum += AttackRangeNumBuff;
	}

	void CloseSkill() override{
		SkillOpen = false;
		AttackNum /= AttackBuff;
        AttackRangeNum -= AttackRangeNumBuff;
	}

protected:

};

#endif

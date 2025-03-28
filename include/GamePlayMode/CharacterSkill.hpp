#ifndef CHARACTER_SKILL_HPP
#define CHARACTER_SKILL_HPP
#include "AnimatedCharacter.hpp"
class CharacterSkill(){
public:
    CharacterSkill(std::string name, std::nameInfo) : SkillName(name), SkillInfo(nameInfo){

    }
    void SetSkill(){

    }
    ~CharacterSkill(){}
protected:
    std::string SkillName;
    std::string SkillInfo;
    float SetTimeBuff = 0;
    int SetCostBuff = 0;
    float AttackTimeBuff = 0;
    float HealthBuff = 0;
    float AttackBuff = 0;
    float DefendBuff = 0;
    int MagicDefendBuff = 0;
    std::shared_ptr<std::vector <Block> >AttackRangeBuff = nullptr;
	int SkillDefaultBuff = 0;
    int SkillCostBuff = 0;
    float SkillTimeBuff = 0;

    int HeavyLevelBuff = 0;
	int HealthRecoverBuff = 0;

	bool DizzyAttackBuff = false;
	bool SleepAttackBuff = false;
	bool FrozenAttackBuff = false;

};

#endif

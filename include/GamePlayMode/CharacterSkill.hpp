#ifndef CHARACTER_SKILL_HPP
#define CHARACTER_SKILL_HPP
#include "GamePlayMode/CharacterAttackImpact.hpp"
#include "Block.hpp"
class CharacterSkill{
public:
    CharacterSkill(){

    }
	
	//void Set

    void SetSetTimeBuff(float timeBuff) {
        SetTimeBuff = timeBuff;
    }

    void SetSetCostBuff(int costBuff) {
        SetCostBuff = costBuff;
    }

    void SetAttackTimeBuff(float attackTimeBuff) {
        AttackTimeBuff = attackTimeBuff;
    }

    void SetHealthBuff(float healthBuff) {
        HealthBuff = healthBuff;
    }

    void SetAttackBuff(float attackBuff) {
        AttackBuff = attackBuff;
    }

    void SetDefendBuff(float defendBuff) {
        DefendBuff = defendBuff;
    }

    void SetMagicDefendBuff(int magicDefendBuff) {
        MagicDefendBuff = magicDefendBuff;
    }
	
	void SetAttackRangeNumBuff(int in){
		AttackRangeNumBuff = in;
	}
    void SetAttackRangeBuff(std::shared_ptr<std::vector<Block>> rangeBuff) {
        AttackRangeBuff = rangeBuff;
    }

    void SetSkillDefaultBuff(int defaultBuff) {
        SkillDefaultBuff = defaultBuff;
    }

    void SetSkillCostBuff(int costBuff) {
        SkillCostBuff = costBuff;
    }

    void SetSkillTimeBuff(float skillTimeBuff) {
        SkillTimeBuff = skillTimeBuff;
    }

    void SetHeavyLevelBuff(int heavyLevelBuff) {
        HeavyLevelBuff = heavyLevelBuff;
    }

    void SetHealthRecoverBuff(int healthRecoverBuff) {
        HealthRecoverBuff = healthRecoverBuff;
    }

    void SetImpact(CharacterAttackImpact temp) {
        ImpactBuff = temp;
    }
	
	void SetType(CharacterAttackType temp){
		TypeBuff = temp;
	}
	
	bool GetSkillOpen(){
		return SkillOpen;
	}

	void SetSkillOpen(bool t){
		SkillOpen = t;
	}

	void SetAttackTimesBuff(int i){
        AttackTimes = i;
    }

    int GetAttackTimesBuff(){
        return AttackTimes;
    }

    ~CharacterSkill(){}
protected:
	bool SkillOpen = false;
    float SetTimeBuff = 0;
    int SetCostBuff = 0;
    float AttackTimeBuff = 0;
    float HealthBuff = 0;
    float AttackBuff = 0;
    float DefendBuff = 0;
    int MagicDefendBuff = 0;
	int AttackRangeNumBuff = 0;
    std::shared_ptr<std::vector<std::vector<std::string>>> m_RangeBuff;
    std::shared_ptr<std::vector <Block> >AttackRangeBuff = nullptr;
	int SkillDefaultBuff = 0;
    int SkillCostBuff = 0;
    float SkillTimeBuff = 0;

    int HeavyLevelBuff = 0;
	int HealthRecoverBuff = 0;
	
	CharacterAttackType TypeBuff = CharacterAttackType::Physics;
	CharacterAttackImpact ImpactBuff = CharacterAttackImpact::Null;

    int AttackTimes = 1;

};

#endif

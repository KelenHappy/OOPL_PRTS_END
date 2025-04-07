#include "Enemy/Enemy.hpp"

#include "move.hpp"
#include "MyTool.hpp"

void Enemy::Updatemove() {
	moveGameObject(shared_from_this(),PathPoints->GetindexPoint(PathPointsindex)+glm::vec2{0,250*abs(m_Transform.scale.y)},MoveSpeedNum*5);
	if (glm::length(m_Transform.translation-(PathPoints->GetindexPoint(PathPointsindex)+glm::vec2{0,250*abs(m_Transform.scale.y)}))<5) {
		PathPointsindex++;
	}
}

void Enemy::takeDamage(CharacterAttackImpact impact, float damage){
	switch(impact){
		case CharacterAttackImpact::Null:
			HealthNum -= damage;
			break;
		case CharacterAttackImpact::Dizzy:
			ImpactDizzy();
			HealthNum -= damage;
			break;
		case CharacterAttackImpact::Sleep:
			ImpactSleep();
			break;
		case CharacterAttackImpact::Frozen:
			ImpactFrozen();
			HealthNum -= damage;
			break;
		default:
			std::cout << "Take DamageError." << std::endl;
			break;
	}
}

void Enemy::ApplySkillEffects() {
    //if (SetTimeBuff > 0) SetTimeNum *= SetTimeBuff;
	//if (SetCostBuff > 0) SetCostNum -= SetCostBuff;
	if (AttackTimeBuff > 0 and AttackTimeBuff < 1) AttackSpeedNum *= AttackTimeBuff;
	if (HealthBuff > 0)	HealthNum *= HealthBuff;
	if (AttackBuff > 0) AttackNum *= AttackBuff;
	if (DefendBuff > 0) DefendNum *= DefendBuff;
	if (MagicDefendBuff > 0) MagicDefendNum *= MagicDefendBuff;
	//if (AttackRangeBuff != nullptr) AttackRangeNow = AttackRangeBuff;
	//if (SkillDefaultBuff > 0) SkillDefaultNum -= SkillDefaultBuff;
	//if (SkillCostBuff > 0) SkillCostNum -= SkillCostBuff;
	//if (SkillTimeBuff > 0) SkillTimeNum *= SkillTimeBuff;
	
	if (HeavyLevelBuff > 0) HeavyLevelNum += HeavyLevelBuff;
	if (HealthRecoverBuff > 0) HealthRecoverNum += HealthRecoverBuff;

	if (ImpactBuff != CharacterAttackImpact::Null) AttackImpact = ImpactBuff;
	if (TypeBuff != AttackType) AttackType = TypeBuff;
}

void Enemy::CloseSkill(){
	//if (SetTimeBuff > 0 and SetTimeBuff < 1) SetTimeNum /= SetTimeBuff;
	//if (SetCostBuff > 0) SetCostNum += SetCostBuff;
	if (AttackTimeBuff > 0 and AttackTimeBuff < 1) AttackSpeedNum /= AttackTimeBuff;
	if (HealthBuff > 0)	HealthNum /= HealthBuff;
	if (AttackBuff > 0) AttackNum /= AttackBuff;
	if (DefendBuff > 0) DefendNum /= DefendBuff;
	if (MagicDefendBuff > 0) MagicDefendNum /= MagicDefendBuff;
	//if (AttackRangeBuff != nullptr) AttackRangeNow = AttackRangeDefault;
	//if (SkillDefaultBuff > 0) SkillDefaultNum += SkillDefaultBuff;
	//if (SkillCostBuff > 0) SkillCostNum += SkillCostBuff;
	//if (SkillTimeBuff > 0 and SkillTimeBuff < 1) SkillTimeNum /= SkillTimeBuff;
	if (HeavyLevelBuff > 0) HeavyLevelNum -= HeavyLevelBuff;
	if (HealthRecoverBuff > 0) HealthRecoverNum -= HealthRecoverBuff;

	if (ImpactBuff != CharacterAttackImpact::Null) AttackImpact = CharacterAttackImpact::Null;
	if (TypeBuff != AttackType) AttackType = CharacterAttackType::Physics;
}

void Enemy::ImpactDizzy(){
	SetAttackTimeBuff(1000);
	Enemy::ApplySkillEffects();
}

void Enemy::ImpactSleep(){
	SetAttackTimeBuff(1000);
	Enemy::ApplySkillEffects();
}

void Enemy::ImpactFrozen(){
	SetAttackTimeBuff(1000);
	Enemy::ApplySkillEffects();
}
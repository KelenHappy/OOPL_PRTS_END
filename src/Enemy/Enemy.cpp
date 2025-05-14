#include "Enemy/Enemy.hpp"

//#include <d3d11sdklayers.h>


#include "move.hpp"
#include "MyTool.hpp"

void Enemy::Updatemove() {
	switch (m_CurrentState) {
		case EnemyState::Move:
			if (glm::length(m_Transform.translation-(PathPoint->GetindexPoint(PathPointsindex)+glm::vec2{0,250*abs(m_Transform.scale.y)}))<3) {
				if (PathPoint->GetIndexWaitPoint(PathPointsindex)<=0){
					PathPointsindex++;
					RodeWaitTime=0;}
				else {
					SetState(EnemyState::Idle);
				}
			}
		else {
			moveGameObject(shared_from_this(),PathPoint->GetindexPoint(PathPointsindex)+glm::vec2{0,250*abs(m_Transform.scale.y)},MoveSpeedNum*2.5);
			}
			I_Hpbar->m_Transform.translation=GetPositionFix()-glm::vec2{ 0,16 };
			break;
		case  EnemyState::Idle:
				RodeWaitTime++;
				//std::cout << RodeWaitTime<<" "<<PathPoint->GetIndexWaitPoint(PathPointsindex)*20<<std::endl;
				if (RodeWaitTime>PathPoint->GetIndexWaitPoint(PathPointsindex)*20) {
					PathPointsindex++;
					RodeWaitTime=0;
					SetState(EnemyState::Move);
				}
			break;

		default:
			break;
	}

}

void Enemy::takeDamage(CharacterAttackImpact impact, float damage){
	switch(impact){
		case CharacterAttackImpact::Null:
			HealthRecoverNum -= damage;
			break;
		case CharacterAttackImpact::Dizzy:
			ImpactDizzy();
			HealthRecoverNum -= damage;
			break;
		case CharacterAttackImpact::Sleep:
			ImpactSleep();
			break;
		case CharacterAttackImpact::Frozen:
			ImpactFrozen();
			HealthRecoverNum -= damage;
			break;
		default:
			std::cout << "Take DamageError." << std::endl;
			break;
	}
	I_Hpbar->Update(HealthRecoverNum,HealthNum);
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
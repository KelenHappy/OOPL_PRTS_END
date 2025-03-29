#include "AnimatedCharacter.hpp"


// 更換Animation
void AnimatedCharacter::Update() {
	switch (m_CurrentState) {
		case CharacterState::Idle:
			m_Drawable = m_IdleAnimation;
			break;
		case CharacterState::Attack:
			m_Drawable = m_AttackAnimation;
			break;
		case CharacterState::Die:
			m_Drawable= m_DieAnimation;
			break;
		case CharacterState::Default:
			m_Drawable = m_Default;
			break;
		case CharacterState::Start:
			m_Drawable= m_StartAnimation;
			break;
		default:
			std::cout << "Error input Current CharacterState" << std::endl;
			break;
	}
}	

[[nodiscard]] bool AnimatedCharacter::IfAnimationEnds() {
	auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
	//std::cout << animation->GetFrameCount() << std::endl;
	return animation->GetCurrentFrameIndex() == animation->GetFrameCount() - 1;
}

void AnimatedCharacter::takeDamage(CharacterAttackImpact impact, float damage){
	switch(impact){
		case CharacterAttackImpact::Null:
			break;
		case CharacterAttackImpact::Dizzy:
			ImpactDizzy();
			break;
		case CharacterAttackImpact::Sleep:
			ImpactSleep();
			break;
		case CharacterAttackImpact::Frozen:
			ImpactFrozen();
			break;
		default:
			std::cout << "Take DamageError." << std::endl;
			break;
	}
	HealthNum -= damage;
}

void AnimatedCharacter::ImpactDizzy(){
	
}

void AnimatedCharacter::ImpactSleep(){
	
}

void AnimatedCharacter::ImpactFrozen(){
	
}

[[nodiscard]] bool AnimatedCharacter::IfCollides( std::shared_ptr<AnimatedCharacter>& other) {
	/*
	 * std::shared_ptr<Util::Amimation> temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
	 */
	if (!other->GetVisibility()) {
		return true;
	}

	glm::vec2 thisPos = this->GetPosition();
	glm::vec2 otherPos = other->GetPosition();

	// 計算碰撞邊界框
	float thisLeft = thisPos.x - m_Width / 2.0f;
	float thisRight = thisPos.x + m_Width / 2.0f;
	float thisTop = thisPos.y - m_Height / 2.0f;
	float thisBottom = thisPos.y + m_Height / 2.0f;

	float otherLeft = otherPos.x - m_Width / 2.0f;
	float otherRight = otherPos.x + m_Width / 2.0f;
	float otherTop = otherPos.y - m_Height / 2.0f;
	float otherBottom = otherPos.y + m_Height / 2.0f;

	// 檢查 X 軸和 Y 軸是否重疊
    bool xContact = (thisRight > otherLeft && thisLeft < otherRight);
    bool yContact = (thisBottom > otherTop && thisTop < otherBottom);

    return xContact && yContact; // 只有 X 和 Y 軸都重疊才判定為碰撞
}

void AnimatedCharacter::ApplySkillEffects() {
    if (SetTimeBuff < 0) SetTimeNum *= SetTimeBuff;
	if (SetCostBuff > 0) SetCostNum -= SetCostBuff;
	if (AttackTimeBuff < 0) AttackTimeNum *= AttackTimeBuff;
	if (HealthBuff > 0)	HealthNum *= HealthBuff;
	if (AttackBuff > 0) AttackNum *= AttackBuff;
	if (DefendBuff > 0) DefendNum *= DefendBuff;
	if (MagicDefendBuff > 0) MagicDefendNum *= MagicDefendBuff;
	if (AttackRangeBuff != nullptr) AttackRangeNow = AttackRangeBuff;
	if (SkillDefaultBuff > 0) SkillDefaultNum -= SkillDefaultBuff;
	if (SkillCostBuff > 0) SkillCostNum -= SkillCostBuff;
	if (SkillTimeBuff < 0) SkillTimeNum *= SkillTimeBuff;
	
	if (HeavyLevelBuff > 0) HeavyLevelNum += HeavyLevelBuff;
	if (HealthRecoverBuff > 0) HealthRecoverNum += HealthRecoverBuff;

	if (ImpactBuff != CharacterAttackImpact::Null) AttackImpact = ImpactBuff;
	if (TypeBuff != AttackType) AttackType = TypeBuff;
}
	

void AnimatedCharacter::CloseSkill(){
	if (SetTimeBuff < 0) SetTimeNum /= SetTimeBuff;
	if (SetCostBuff > 0) SetCostNum += SetCostBuff;
	if (AttackTimeBuff < 0) AttackTimeNum /= AttackTimeBuff;
	if (HealthBuff > 0)	HealthNum /= HealthBuff;
	if (AttackBuff > 0) AttackNum /= AttackBuff;
	if (DefendBuff > 0) DefendNum /= DefendBuff;
	if (MagicDefendBuff > 0) MagicDefendNum /= MagicDefendBuff;
	if (AttackRangeBuff != nullptr) AttackRangeNow = AttackRangeDefault;
	if (SkillDefaultBuff > 0) SkillDefaultNum += SkillDefaultBuff;
	if (SkillCostBuff > 0) SkillCostNum += SkillCostBuff;
	if (SkillTimeBuff < 0) SkillTimeNum /= SkillTimeBuff;
	if (HeavyLevelBuff > 0) HeavyLevelNum -= HeavyLevelBuff;
	if (HealthRecoverBuff > 0) HealthRecoverNum -= HealthRecoverBuff;

	if (ImpactBuff != CharacterAttackImpact::Null) AttackImpact = CharacterAttackImpact::Null;
	if (TypeBuff != AttackType) AttackType = CharacterAttackType::Physics;
}
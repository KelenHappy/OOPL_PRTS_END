#include "Character/AnimatedCharacter.hpp"


// 更換Animation
void AnimatedCharacter::Update() {
	switch (m_CurrentState) {
		case CharacterState::Start:
			m_Drawable= m_StartAnimation;
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
		case CharacterState::Idle:
			m_Drawable = m_IdleAnimation;
			break;
		case CharacterState::HalfCard:
			m_Drawable = m_HalfCard;
			break;
		default:
			std::cout << "Error input Current CharacterState" << std::endl;
			break;
	}
}	

[[nodiscard]] bool AnimatedCharacter::IfAnimationEnds() const{
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
	//std::cout << damage << std::endl;
	HealthRecoverNum -= damage;
	m_HpBar->Update(HealthRecoverNum,HealthNum);
}
void AnimatedCharacter::CharacterGetBuff(){

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

void AnimatedCharacter::FrameReset(){
	m_IdleAnimation->SetCurrentFrame(0);
    m_AttackAnimation->SetCurrentFrame(0);
    m_DieAnimation->SetCurrentFrame(0);
    m_StartAnimation->SetCurrentFrame(0);
    m_Default->SetCurrentFrame(0);
	
}
void AnimatedCharacter::updatetransform() {
	m_HpBar->m_Transform.translation=GetPositionFix()-glm::vec2{0,20};
}
void AnimatedCharacter::PlaceCharacter(std::shared_ptr<Block> block,int index) {
	if (block == nullptr) return;

	// 重置所有狀態
	DefendCoutNow = 0;
	Dead = false;  // 重要：重置死亡狀態

	// 清理並釋放所有被阻擋的敵人
	for (size_t i = 0; i < m_GotAttackEnemy.size(); i++) {
		if (m_GotAttackEnemy[i]) {
			m_GotAttackEnemy[i]->SetStuck(false);
		}
	}
	m_GotAttackEnemy.resize(0);  // 清空容器

	// 重置生命值
	HealthRecoverNum = HealthNum;
	m_HpBar->Update(HealthRecoverNum, HealthNum);

	// 重置攻擊計時器
	AttackTimeTicket = -1;

	// 設置位置和狀態
	m_PlaceBlock = block;
	SetPosition(block->GetPosition());
	SetState(CharacterState::Start);
	SetVisible(true);
	Gethpbar()->SetVisible(true);
	block->placeCharacter(index);
	updatetransform();
}
void AnimatedCharacter::OutPlaceCharacter() {
	for (size_t i = 0; i < m_GotAttackEnemy.size(); i ++) {
		m_GotAttackEnemy[i]->SetStuck(false);
	}
	m_HpBar->Update(HealthRecoverNum,HealthNum);
	FrameReset();
	SetHP();
	SetDieCost();
	SetDead(true);
	SetVisible(false);
	Gethpbar()->SetVisible(false);
	SetLooping(false);
	SetState(CharacterState::Default);
	ClearAllGotEnemies();
	CloseSkill();
	PlaceCostNum=std::min(int(PlaceCostNum*1.5),int(SetCostNum*2));
	m_PlaceBlock->outplaceCharacter();
	m_PlaceBlock=nullptr;
}
void AnimatedCharacter::showrange() {
	for(size_t i=0;i<AttackRangeNow.size();i++) {
		AttackRangeNow[i]->SetVisible(true);
		AttackRangeNow[i]->ChangeImage("/Maps/Attackrange.png");
	}
}

void AnimatedCharacter::ClearAllGotEnemies() {
	// 將所有被阻擋的敵人設為未被阻擋
	for (auto& enemy : m_GotAttackEnemy) {
		if (enemy) {
			enemy->SetStuck(false);
		}
	}
	m_GotAttackEnemy.clear();
	DefendCoutNow = 0;  // 重置防禦計數
}
void AnimatedCharacter::RestartOfStart() {
	PlaceCostNum=SetCostNum;
	SetHP();
	SetDieCost();
	SetDead(false);
	SetLooping(false);
	SetState(CharacterState::Default);
}



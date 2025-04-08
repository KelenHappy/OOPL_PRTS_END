#ifndef ANIMATED_CHARACTER_HPP
#define ANIMATED_CHARACTER_HPP

#include <vector>
#include <string>
#include <iostream>
#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"
#include "CharacterState.hpp"
#include "ClassState.hpp"
#include "BlockState.hpp"

#include "GamePlayMode/CharacterAttackImpact.hpp"
#include "GamePlayMode/CharacterSkill.hpp"
#include "GamePlayMode/AttackRange.hpp"

class AnimatedCharacter : public Util::GameObject, public CharacterSkill , public AttackRange{
public:
	// IdleEnd, AttackEnd, DieEnd, StartEnd, Default
    // AnitmationPaths 使用 default path
    AnimatedCharacter()
        : m_CurrentState(CharacterState::Default) {
    }
    
	// Function
	void Update();
    [[nodiscard]] bool IfCollides( std::shared_ptr<AnimatedCharacter>& other);
	void ApplySkillEffects();
	void CloseSkill();
	void takeDamage(CharacterAttackImpact impact, float damage);
	void ImpactDizzy();
	void ImpactSleep();
	void ImpactFrozen();
	void FrameReset();
	
	[[nodiscard]] bool IfAnimationEnds() const;
	
	// Set
	//設定path
    void SetPath(std::vector<std::string>& IdleEnd,
                 std::vector<std::string>& AttackEnd,
                 std::vector<std::string>& DieEnd,
                 std::vector<std::string>& StartEnd,
                 std::vector<std::string>& DefaultEnd){
        // 初始化動畫
        this->m_Drawable = std::make_shared<Util::Animation>
        (DefaultEnd, false, 40, false, 35);
        this->m_Default = std::make_shared<Util::Animation>
        (DefaultEnd, false, 40, false, 35);
        this->m_Drawable = m_Default;

        this->m_IdleAnimation = std::make_shared<Util::Animation>
        (IdleEnd, false, 40, false, 35);
        this->m_AttackAnimation = std::make_shared<Util::Animation>
        (AttackEnd, false, 40, false, (int)GetAttackTime()*1000);
        this->m_DieAnimation = std::make_shared<Util::Animation>
        (DieEnd, false, 40, false, 35);
        this->m_StartAnimation = std::make_shared<Util::Animation>
        (StartEnd, false, 40, false, 35);
    }
	
	//Set 圖片大小
	void SetImageSize(float x, float y){
		m_Transform.scale={x, y}; 
	}
	
	void SetPosition(const glm::vec2& Position) { 
		m_Transform.translation = {Position.x, Position.y + 80};
	}
	
	void SetState(CharacterState temp) {
		//StopCurrentAnimation();
		m_CurrentState = temp;
		Update();
	}
	
    void SetLooping(bool looping) {
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        //temp->SetLooping(looping);
        if(looping)temp->Play();
        else{
            temp->Pause();
        }
    }
	
    void SetInfo(float SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
    int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname, int DefendCout
    ){
        SetTimeNum = SetTime;
        SetCostNum = SetCost;
        AttackTimeNum = AttackTime;
        HealthNum = Health;
		HealthRecoverNum = Health;
        AttackNum = Attack;
        DefendNum = Defend;
        MagicDefendNum = DefendMagic;
        SkillDefaultNum = SkillDefault;
        SkillCostNum = SkillCost;
        SkillTimeNum = SkillTime;
        SkillInfo = skillinfo;
        SkillName = skillname;
        HeavyLevelNum = DefendCout;
    }
	void SetAttackType(CharacterAttackType tt){
        AttackType = tt;
    }
	
	void SetAttackImpact(CharacterAttackImpact tt){
        AttackImpact = tt;
    }
	
	// Get
	float GetSetTime(){
		return SetTimeNum;
	}
	int GetSetCost(){
		return SetCostNum;
	}
	float GetAttackTime(){
		return AttackTimeNum;
	}
	float GetHP(){
		return HealthNum;
	}
    float GetAttack() { 
		return AttackNum;
	}
	float GetDefend() { 
		return DefendNum;
	}
	float GetMagicDefend() { 
		return MagicDefendNum;
	}
	int GetSkillDefault(){
		return SkillDefaultNum;
	}
    int GetSkillCost(){
		return SkillCostNum;
	}
	float GetSkillTime(){
		return SkillTimeNum;
	}
	std::string GetSkillInfo(){
		return SkillInfo;
	}
    std::string GetSkillName(){
		return SkillName;
	}
    int GetHeavyLevel(){
		return HeavyLevelNum;
	}
	float GetHealthRecover(){
		return HealthRecoverNum;
	}
	
	CharacterAttackImpact GetAttackImpact(){
		return AttackImpact;
	}
    CharacterAttackType GetAttackType(){
		return AttackType;
	}
	
	[[nodiscard]] int GetFrames() {
		return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetCurrentFrameIndex();
	}
	
	
	[[nodiscard]] const glm::vec2& GetPosition() { 
		return m_Transform.translation; 
	}

    [[nodiscard]] bool GetVisibility(){ 
		return m_Visible; 
	}
	
	[[nodiscard]] CharacterState GetState() {
        return m_CurrentState;
    }
	std::string GetCharacterName(){
		return CharacterName;
	}
	void SetCharacterName(std::string name){CharacterName=name;}
	virtual std::string GetJob()=0;
	virtual ClassState GetJobClass()=0;
	virtual BlockState GetBlockState() = 0;
	
	~AnimatedCharacter(){}
protected:
    CharacterState m_CurrentState;
    std::shared_ptr<Util::Animation> m_IdleAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_AttackAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_DieAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_StartAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_Default = nullptr;

    // 角色info
    float SetTimeNum = 0;
    int SetCostNum = 0;
    float AttackTimeNum = 0;
    float HealthNum = 0;
	float HealthNow = 0;
    float AttackNum = 0;
    float DefendNum = 0;
    float MagicDefendNum = 0;
	std::string CharacterName;
	
	//std::shared_ptr<std::vector <Block>> AttackRangeNow = nullptr;
    //std::shared_ptr<std::vector <Block> >AttackRangeDefault = nullptr;
	int SkillDefaultNum = 0;
    int SkillCostNum = 0;
    float SkillTimeNum = 0;
    std::string SkillInfo = "";
    std::string SkillName = "";

    int HeavyLevelNum = 0;
	float HealthRecoverNum = 0;
    CharacterAttackType AttackType = CharacterAttackType::Physics;
	CharacterAttackImpact AttackImpact = CharacterAttackImpact::Null;

private:
    float m_Width = 15.0f;  // 角色寬度
    float m_Height = 15.0f; // 角色高度
};

#endif // ANIMATED_CHARACTER_HPP

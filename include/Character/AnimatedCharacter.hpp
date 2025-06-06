#ifndef ANIMATED_CHARACTER_HPP
#define ANIMATED_CHARACTER_HPP

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib> 
#include "ImgItem.hpp"
#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"
#include "CharacterState.hpp"
#include "ClassState.hpp"
#include "BlockState.hpp"
#include "Hpbar.hpp"
#include "Enumclass/Direction.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
#include "GamePlayMode/CharacterSkill.hpp"
#include "GamePlayMode/AttackRange.hpp"
#include "GamePlayMode/Buff.hpp"


class AnimatedCharacter : public Util::GameObject, public CharacterSkill , public AttackRange, public Buff{
public:
	// IdleEnd, AttackEnd, DieEnd, StartEnd, Default
    // AnitmationPaths 使用 default path
    AnimatedCharacter()
        : m_CurrentState(CharacterState::Default) {
    }
    
	// Function
	int AttackTimess = 1;
	void Update();
    [[nodiscard]] bool IfCollides( std::shared_ptr<AnimatedCharacter>& other);
	virtual void takeDamage(CharacterAttackImpact impact, float damage);
    void CharacterGetBuff();
	void ImpactDizzy();
	void ImpactSleep();
	void ImpactFrozen();
	void FrameReset();
	void showrange();
    virtual void CreateAnimation() = 0;
	virtual void OpenSkill() = 0;
	virtual void CloseSkill() = 0;
	[[nodiscard]] bool IfAnimationEnds() const;
	void DeDieCost(int i){DieCost -= i;}
	void AddSkillCost(int i){
        SkillNow += i;
        SkillNow = std::min(SkillCostNum,SkillNow);
    }
    void DeSkillTime(int i){
        SkillTimeNum -= i;
    }
	virtual void UpdateEffect() {

	}
	bool BuffTicket = false;
    virtual void BuffU(std::shared_ptr<AnimatedCharacter> getBuff) {
        if (getBuff) {
            getBuff->SetGetBuff(true);
            getBuff->SetBuffTime(5);
            (getBuff)->ApplyBuff(AttackBB, DefendBB, AttackSpeedBB, HPBB);
        }
    }
	void ApplyBuff(float attack, float defend, float attackspeed, float hp) {
        if(GetBuff){
            if(BuffTicket){
                return;
            }
            GAttackBuff = attack;
            GDefendBuff = defend;
            GAttackSpeedBuff = attackspeed;
            GHealthBuff = hp;
            BuffTicket = true;
            AttackNum = (int)(AttackNum * attack);
            DefendNum = (int)(DefendNum * defend);
            AttackTimeNum = (int)(AttackTimeNum * attackspeed);
            HealthRecoverNum = (int)(HealthRecoverNum * hp);
        }
    }
    void CloseBuff(){
        if(GetBuff){
            BuffTicket = false;
            AttackNum /= GAttackBuff;
            DefendNum /= GDefendBuff;
            AttackTimeNum /= GAttackSpeedBuff;
        }
    }

    void DeAttackTime(){
        AttackTimeTicket -= 1;
    }
	// Set
	//設定path
    void SetPath(std::vector<std::string>& IdleEnd,
                 std::vector<std::string>& AttackEnd,
                 std::vector<std::string>& DieEnd,
                 std::vector<std::string>& StartEnd,
                 std::vector<std::string>& DefaultEnd){
        // 初始化動畫
        this->m_Default = std::make_shared<Util::Animation>
        (DefaultEnd, false, 40, false, 40);
        this->m_Drawable = m_Default;
        this->m_IdleAnimation = std::make_shared<Util::Animation>
        (IdleEnd, false, 50, false, 40);
        this->m_AttackAnimation = std::make_shared<Util::Animation>
        (AttackEnd, false, 40, false, 40);
        this->m_DieAnimation = std::make_shared<Util::Animation>
        (DieEnd, false, 40, false, 40);
        this->m_StartAnimation = std::make_shared<Util::Animation>
        (StartEnd, false, 40, false, 40);
    	m_HpBar = std::make_shared<HpBar>();
    }
	
	//Set 圖片大小
	void SetImageSize(float x, float y){
		m_Transform.scale={x, y}; 
	}
	
	void SetPosition(const glm::vec2& Position) { 
		m_Transform.translation = {Position.x, Position.y + 250*m_Transform.scale.y};
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
        DieCost = SetTime;
        SetCostNum = SetCost;
        AttackTimeNum = AttackTime;
        AttackTimeTicket = -1;
        HealthNum = Health;
		HealthRecoverNum = Health;
        AttackNum = Attack;
        DefendNum = Defend;
        MagicDefendNum = DefendMagic;
        SkillDefaultNum = SkillDefault;
        SkillNow = SkillDefault;
        SkillCostNum = SkillCost;
        SkillTimeNum = SkillTime;
        SkillInfo = skillinfo;
        SkillName = skillname;
        HeavyLevelNum = DefendCout;
    }
    void SetHP(){HealthRecoverNum = HealthNum;}
    void SetAttackTimeTicket(float in){AttackTimeTicket = in;}
	void SetAttackType(CharacterAttackType tt){AttackType = tt;}
	void SetAttackImpact(CharacterAttackImpact tt){AttackImpact = tt;}
	void SetDead(bool t){ Dead = t;}
	void SetDieCost(){ DieCost = SetTimeNum;}
	void updatetransform();
	void SetAttackRangeDefault(std::vector<std::shared_ptr <Block>>AD){AttackRangeDefault=AD;AttackRangeNow=AD;}
	// Get
	int GetSkillNow(){return SkillNow;}
	float GetAttackTimeTicket(){return AttackTimeTicket;}
	float GetSetTime(){return SetTimeNum;}
	int GetSetCost(){return SetCostNum;}
	float GetAttackTime(){return AttackTimeNum;}
	float GetHP(){return HealthNum;}
    float GetAttack() { return AttackNum;}
	float GetDefend() { return DefendNum;}
	float GetMagicDefend() { return MagicDefendNum;}
	int GetSkillDefault(){return SkillDefaultNum;}
    int GetSkillCost(){return SkillCostNum;}
	float GetSkillTime(){return SkillTimeNum;}
	std::shared_ptr<HpBar> Gethpbar(){return m_HpBar;}
	glm::vec2 GetPositionFix(){return m_Transform.translation-glm::vec2{0,250*m_Transform.scale.y};}
	std::string GetSkillInfo(){return SkillInfo;}
    std::string GetSkillName(){return SkillName;}
    int GetHeavyLevel(){return HeavyLevelNum;}
	float GetHealthRecover(){return HealthRecoverNum;}
	CharacterAttackImpact GetAttackImpact(){return AttackImpact;}
    CharacterAttackType GetAttackType(){return AttackType;}
    bool GetDie(){return Dead;}
    int GetDieCost(){return DieCost;}
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
	virtual std::string GetChineseName()=0;
	void PlaceCharacter(std::shared_ptr<Block> block,int index);
	std::shared_ptr<Block> GetPlaceBlock(){return m_PlaceBlock;}
	void OutPlaceCharacter();
	~AnimatedCharacter(){}
protected:
    CharacterState m_CurrentState;
    std::shared_ptr<Util::Animation> m_IdleAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_AttackAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_DieAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_StartAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_Default = nullptr;
	std::shared_ptr<Util::Animation> m_HalfCard = nullptr;
	std::shared_ptr<HpBar> m_HpBar = nullptr;

    // 角色info
    float SetTimeNum = 0;
    int SetCostNum = 0;
    float AttackTimeNum = 0;
    float AttackTimeTicket = -1;
    float HealthNum = 0;
    float AttackNum = 0;
    float DefendNum = 0;
    float MagicDefendNum = 0;
	std::string CharacterName;
	std::shared_ptr<Block> m_PlaceBlock = nullptr;
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

    //Die Control
    bool Dead = false;
    int DieCost = 0;
    // Slill Control
    int SkillNow = 0;
    // Buff Control


private:
    float m_Width = 15.0f;  // 角色寬度
    float m_Height = 15.0f; // 角色高度
};

#endif // ANIMATED_CHARACTER_HPP

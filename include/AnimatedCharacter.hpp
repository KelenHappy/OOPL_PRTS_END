#ifndef ANIMATED_CHARACTER_HPP
#define ANIMATED_CHARACTER_HPP

#include "Block.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"
#include "CharacterState.hpp"
#include "AnimatedEnemy.hpp"

class AnimatedCharacter : public Util::GameObject {
public:
	// IdleEnd, AttackEnd, DieEnd, StartEnd, Default
    // AnitmationPaths 使用 default path
    AnimatedCharacter()
        : m_CurrentState(CharacterState::Default) {
    }
    //設定path
    void SetPath(std::vector<std::string>& IdleEnd,
                 std::vector<std::string>& AttackEnd,
                 std::vector<std::string>& DieEnd,
                 std::vector<std::string>& StartEnd,
                 std::vector<std::string>& DefaultEnd){
        // 初始化動畫
        this->m_Drawable = std::make_shared<Util::Animation>
        (DefaultEnd, false, 50, false, 0);
        this->m_Default = std::make_shared<Util::Animation>
        (DefaultEnd, false, 50, false, 0);
        this->m_Drawable = m_Default;

        this->m_IdleAnimation = std::make_shared<Util::Animation>
        (IdleEnd, false, 50, false, 0);
        this->m_AttackAnimation = std::make_shared<Util::Animation>
        (AttackEnd, false, 50, false, 0);
        this->m_DieAnimation = std::make_shared<Util::Animation>
        (DieEnd, false, 50, false, 0);
        this->m_StartAnimation = std::make_shared<Util::Animation>
        (StartEnd, false, 50, false, 0);
    }
    // 更換Animation
    void Update() {
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

    [[nodiscard]] CharacterState GetState() {
        return m_CurrentState;
    }

    void SetState(CharacterState temp) {
		//StopCurrentAnimation();
		m_CurrentState = temp;
		Update();
	}

	[[nodiscard]] bool IfAnimationEnds() {
        auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        //std::cout << animation->GetFrameCount() << std::endl;
        return animation->GetCurrentFrameIndex() == animation->GetFrameCount() - 1;
    }

    [[nodiscard]] const glm::vec2& GetPosition() { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility(){ return m_Visible; }

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    [[nodiscard]] int GetFrames() {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetCurrentFrameIndex();
    }

    [[nodiscard]] bool IfCollides( std::shared_ptr<AnimatedCharacter>& other) {
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

    void SetLooping(bool looping) {
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->SetLooping(looping);
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
	
	void SetRange(std::shared_ptr<std::vector<Block>> Range){
		if (Range) {  // 避免空指针
            AttackRange = std::make_shared<std::vector<Block>>(*Range); // 	複製vector 數據
        }		
	}
	
	int GetHP(){
		return HealthNum;
	}

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
    float AttackNum = 0;
    float DefendNum = 0;
    int MagicDefendNum = 0;
    std::shared_ptr<std::vector <Block> >AttackRange = nullptr;
	int SkillDefaultNum = 0;
    int SkillCostNum = 0;
    float SkillTimeNum = 0;
    std::string SkillInfo = "";
    std::string SkillName = "";

    int HeavyLevelNum = 0;
	int HealthRecoverNum = 0;

	bool DizzyAttack = false;
	bool SleepAttack = false;
	bool FrozenAttack = false;

private:
    float m_Width = 15.0f;  // 角色寬度
    float m_Height = 15.0f; // 角色高度
};

#endif // ANIMATED_CHARACTER_HPP

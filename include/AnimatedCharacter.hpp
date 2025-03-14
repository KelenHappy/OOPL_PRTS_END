#ifndef ANIMATED_CHARACTER_HPP
#define ANIMATED_CHARACTER_HPP

#include <vector>
#include <string>
#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"
#include "CharacterState.hpp"
#include "AnimatedEnemy.hpp"

class AnimatedCharacter : public Util::GameObject {
public:
	// IdleEnd, AttackEnd, DieEnd, StartEnd, Default
    // AnitmationPaths 使用 default path
    AnimatedCharacter(const std::vector<std::string>& AnimationPaths,
                      const std::vector<std::string>& IdleEnd = {},
                      const std::vector<std::string>& AttackEnd = {},
                      const std::vector<std::string>& DieEnd = {},
                      const std::vector<std::string>& StartEnd = {},
                      const std::vector<std::string>& Default= {})
        : m_CurrentState(CharacterState::Default) {
        // 初始化動畫
        this->m_Drawable = std::make_shared<Util::Animation>
        (AnimationPaths, false, 50, false, 0);
        this->m_IdleAnimation = std::make_shared<Util::Animation>
        (IdleEnd, true, 100, true);
        this->m_AttackAnimation = std::make_shared<Util::Animation>
        (AttackEnd, true, 50, false);
        this->m_DieAnimation = std::make_shared<Util::Animation>
        (DieEnd, true, 100, false);
        this->m_StartAnimation = std::make_shared<Util::Animation>
        (StartEnd, true, 100, false);
        this->m_Default = std::make_shared<Util::Animation>
        (Default, true, 100, false);
        this->m_Drawable = m_Default;
    }
    // 更換Animation
    void Update() {
        switch (m_CurrentState) {
            case CharacterState::Idle:
                if (m_IdleAnimation->GetState() != Util::Animation::State::PLAY) {
                    m_Drawable = m_IdleAnimation;
                }
                break;
            case CharacterState::Attack:
                if (m_AttackAnimation->GetState() != Util::Animation::State::PLAY) {
                    m_Drawable = m_AttackAnimation;
                }
                break;
            case CharacterState::Die:
                if (m_DieAnimation->GetState() != Util::Animation::State::PLAY) {
                    m_Drawable= m_DieAnimation;
                }
                break;
            case CharacterState::Default:
                if (m_Default->GetState() != Util::Animation::State::PLAY) {
                    m_Drawable = m_Default;
                }
                break;
            case CharacterState::Start:
                if (m_StartAnimation->GetState() != Util::Animation::State::PLAY) {
                    m_Drawable= m_StartAnimation;
                }
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

    void SetPosition(glm::vec2& Position) { m_Transform.translation = Position; }

    [[nodiscard]] int GetFrames() {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetCurrentFrameIndex();
    }

    [[nodiscard]] bool IfCollides( std::shared_ptr<AnimatedCharacter>& other) {
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

private:
    CharacterState m_CurrentState;
    std::shared_ptr<Util::Animation> m_IdleAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_AttackAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_DieAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_StartAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_Default = nullptr;

    float m_Width = 15.0f;  // 角色寬度
    float m_Height = 15.0f; // 角色高度
};

#endif // ANIMATED_CHARACTER_HPP

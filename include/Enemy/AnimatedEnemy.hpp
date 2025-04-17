#ifndef ANIMATED_ENEMY_HPP
#define ANIMATED_ENEMY_HPP

#include <vector>
#include <string>
#include <iostream>

#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"
#include "EnemyState.hpp"


class AnimatedEnemy : public Util::GameObject {
public:
	// IdleEnd, AttackEnd, DieEnd, MoveEnd, Default
    // AnitmationPaths 使用 default path
    AnimatedEnemy()
        : m_CurrentState(EnemyState::Default) {
    }
    // 設定path
    void SetPath(std::vector<std::string>& IdleEnd,
                 std::vector<std::string>& AttackEnd,
                 std::vector<std::string>& DieEnd,
                 std::vector<std::string>& MoveEnd,
                 std::vector<std::string>& DefaultEnd){
        // 初始化動畫
        this->m_Drawable = std::make_shared<Util::Animation>
        (DefaultEnd, false, 50, false, 50);
        this->m_Default = std::make_shared<Util::Animation>
        (DefaultEnd, false, 50, false, 50);
        this->m_IdleAnimation = std::make_shared<Util::Animation>
        (IdleEnd, false, 50, false, 50);
        this->m_AttackAnimation = std::make_shared<Util::Animation>
        (AttackEnd, false, 50, false, 500);
        this->m_DieAnimation = std::make_shared<Util::Animation>
        (DieEnd, false, 50, false, 50);
        this->m_MoveAnimation = std::make_shared<Util::Animation>
        (MoveEnd, false, 50, false, 50);
		this->m_Drawable = m_Default;
    }
    // 更換Animation
    void Update() {
        switch (m_CurrentState) {
            case EnemyState::Idle:
                m_Drawable = m_IdleAnimation;
                break;
            case EnemyState::Attack:
                m_Drawable = m_AttackAnimation;
                break;
            case EnemyState::Die:
                m_Drawable= m_DieAnimation;
                break;
            case EnemyState::Default:
                m_Drawable = m_Default;
                break;
            case EnemyState::Move:
                m_Drawable= m_MoveAnimation;         
                break;
			default:
				std::cout << "Error input Current EnemyState" << std::endl;
				break;
        }
    }

    [[nodiscard]] EnemyState GetState() {
        return m_CurrentState;
    }

	void SetState(EnemyState temp) {
		//StopCurrentAnimation();
		m_CurrentState = temp;
		Update();
	}

    [[nodiscard]] bool IfAnimationEnds() {
        auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        //std::cout << animation->GetFrameCount() << std::endl;
        if(animation) return animation->GetCurrentFrameIndex() == animation->GetFrameCount() - 1;
		return false;
	}

    [[nodiscard]] const glm::vec2& GetPosition() { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility(){ return m_Visible; }

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    [[nodiscard]] int GetFrames() {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetCurrentFrameIndex();
    }

    [[nodiscard]] bool IfCollides( std::shared_ptr<AnimatedEnemy>& other){
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
        if (temp) {
			temp->SetLooping(looping);
			if (looping) {
				temp->Play();
			} 
			else {
				temp->Pause();
			}
		}
    }
	void FrameReset(){
		m_IdleAnimation->SetCurrentFrame(0);
		m_AttackAnimation->SetCurrentFrame(0);
		m_DieAnimation->SetCurrentFrame(0);
		m_MoveAnimation->SetCurrentFrame(0);
		m_Default->SetCurrentFrame(0);
	}
	~AnimatedEnemy(){}
protected:
    EnemyState m_CurrentState;
    std::shared_ptr<Util::Animation> m_IdleAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_AttackAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_DieAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_MoveAnimation = nullptr;
    std::shared_ptr<Util::Animation> m_Default = nullptr;

private:
    float m_Width = 15.0f;  // 角色寬度
    float m_Height = 15.0f; // 角色高度
	
};

#endif // ANIMATED_ENEMY_HPP

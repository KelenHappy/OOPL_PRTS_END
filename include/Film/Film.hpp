#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Color.hpp"
#include "ImgItem.hpp"
#include "Film/FilmState.hpp"
#include <iostream>
#ifndef FILM_HPP
#define FILM_HPP

class Film : public Util::GameObject {  // 使用 public 繼承
public:
    Film(std::string name, std::string ff, FilmState fState) {
        // 假設 RESOURCE_DIR 是有效的並已正確定義
        Impact = ff;
        Name = name+ff;
		FilmSize = 0.6f;
		SetCardSize(FilmSize);
        FilmImage = RESOURCE_DIR"/Film/" + ff + ".png";

        // 假設 Util::Animation 類別有這樣的構造函數
        m_Drawable = std::make_shared<Util::Image>(FilmImage);

        SetZIndex(28);
        switch(fState){
            case FilmState::Die:
                m_Transform.scale = {0.6f, 0.6f};
                break;
            case FilmState::TakeDamage:
                m_Transform.scale = {0.02f, 0.02f};
                break;
            case FilmState::Bullet:
                m_Transform.scale = {0.05f, 0.05f};
                break;
            case FilmState::Frozen:
                m_Transform.scale = {0.05f, 0.05f};
                break;
            default:
                std::cout << "None In Film." << std::endl;
                break;
        }

    }

    ~Film() = default;
	
	void AddLife(int i){
        timers -= i;
        if(timers <= 0){
            SetVisible(false);
        }
    }

    int GetNowLife(){
        return timers;
    }

    int GetlifeTimes(){
        return lifeTimes;
    }


    glm::vec2 GetPosition() const { return m_Transform.translation; }

    std::string GetImpact(){
        return Impact;
    }

    std::string GetName(){
        return Name;
    }
    void setsize(float x, float y) {
        m_Transform.scale = {x, y};  // 假設 m_Transform.scale 是有效的
    }

	void SetPosition(const glm::vec2& Position) {
        m_Transform.translation = {Position.x, Position.y};
    }

    void SetLifeTimes(int i){
        timers = i;
        lifeTimes = i;
    }
	
	void SetCardSize(float size) {
		m_Transform.scale={size,size };
	}
	
	virtual void Update(){
        AddLife(1);
        SetVisible(true);

    }

    virtual void SetEnemyPoint(glm::vec2 EE){
        EnemyPath = EE;
    }

protected:
	float FilmSize = 1;
    int timers = 0;
    int lifeTimes = 0;
	std::string Name = "";
    std::string Impact = "";
    std::string FilmImage;

    glm::vec2 EnemyPath;  // 儲存敵人位置
};

#endif // FILM_HPP

#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"
#include "TextBox.hpp"
#ifndef FILM_HPP
#define FILM_HPP

class Film : public Util::GameObject {  // 使用 public 繼承
public:
    Film() = default;

    Film(std::string ff) {
        // 假設 RESOURCE_DIR 是有效的並已正確定義
        Impact = ff;
        FilmImage.emplace_back(RESOURCE_DIR"/Film/" + ff + ".png");

        // 假設 Util::Animation 類別有這樣的構造函數
        this->m_Drawable = std::make_shared<Util::Animation>(FilmImage, false, 40, false, 40);

        SetZIndex(27);
    }

    ~Film() = default;
	
	void AddLife(int i){
        timers -= i;
    }

    int GetNowLife(){
        return timers;
    }

    int GetlifeTimes(){
        return lifeTimes;
    }

    std::shared_ptr<TextBox> GetText(){return m_Text;}

    glm::vec2 GetPosition() const { return m_Transform.translation; }

    std::string GetImpact(){
        return Impact;
    }

    std::string GetName(){
        return Name;
    }

    void SetLooping(bool looping) {
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        //temp->SetLooping(looping);
        if(looping)temp->Play();
        else{
            temp->Pause();
        }
    }

    void setsize(float x, float y) {
        m_Transform.scale = {x, y};  // 假設 m_Transform.scale 是有效的
    }

	void SetName(std::string name){
		Name = name;
	}

	void SetPosition(const glm::vec2& Position) {
        m_Transform.translation = {Position.x, Position.y};
    }

    void SetLifeTimes(int i){
        timers = i;
        lifeTimes = i;
    }

	void createinfo(std::string txt) {
		m_Text->SetText(txt);
	}
private:
    int timers = 0;
    int lifeTimes = 0;
	std::string Name = "";
    std::string Impact = "";
    std::vector<std::string> FilmImage;
	std::shared_ptr<TextBox> m_Text;
};

#endif // FILM_HPP

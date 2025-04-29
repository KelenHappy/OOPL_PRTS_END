#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"
#include "TextBox.hpp"
#include "ImgItem.hpp"
#ifndef FILM_HPP
#define FILM_HPP

class Film : public Util::GameObject {  // 使用 public 繼承
public:
    Film() = default;

    Film(std::string name, std::string ff) {
        // 假設 RESOURCE_DIR 是有效的並已正確定義
        Impact = ff;
        Name = name+ff;
		FilmSize = 0.8f;
        FilmImage = RESOURCE_DIR"/Film/" + ff + ".png";
        m_Text = std::make_shared<TextBox>(20);
        // 假設 Util::Animation 類別有這樣的構造函數
        m_Drawable = std::make_shared<Util::Image>(FilmImage);

        SetZIndex(28);
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

    std::shared_ptr<ImgItem> GetFilm(){return m_Film;}

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

	void createinfo(std::string txt) {
		m_Text->SetText(txt);
	}

	void Update(){
        AddLife(1);
        m_Text->SetText(std::to_string(timers));
        SetVisible(true);

    }
private:
	float FilmSize = 1;
    int timers = 0;
    int lifeTimes = 0;
	std::string Name = "";
    std::string Impact = "";
    std::string FilmImage;
    std::shared_ptr<ImgItem> m_Film;
	std::shared_ptr<TextBox> m_Text;
};

#endif // FILM_HPP

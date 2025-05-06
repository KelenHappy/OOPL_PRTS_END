#include "Film/Film.hpp"
#ifndef TAKE_DAMAGE_HPP
#define TAKE_DAMAGE_HPP

class TakeDamage : public Film {  // 使用 public 繼承
public:
    TakeDamage(std::string name, std::string ff): Film(name, ff) {
        SetLifeTimes(3);
    }

    ~TakeDamage() = default;


	void Update () override{
        AddLife(1);
        SetVisible(true);

    }

private:

};

#endif // TAKE_DAMAGE_HPP

#ifndef FROZEN_HPP
#define FROZEN_HPP
#include "Film/Film.hpp"
class Frozen : public Film {  // 使用 public 繼承
public:
    Frozen(std::string name, std::string ff): Film(name, ff,FilmState::Frozen) {
        SetLifeTimes(5);
    }

    ~Frozen() = default;


    void Update () override{
        AddLife(1);
        SetVisible(true);

    }

private:

};
#endif //FROZEN_HPP

#ifndef MAPS_H
#define MAPS_H
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Time.hpp"
class MAPS : public Util::GameObject {

public:
    BackgroundImage() : GameObject(
         7/   std::make_unique<Util::Image>(GA_RESOURCE_DIR"/Maps/main_01-0_01-07.png"), -10) {
    }

    void NextPhase(const int phase) {
        auto temp = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
        temp->SetImage(ImagePath(phase));
    }

};

#endif //MAPS_H

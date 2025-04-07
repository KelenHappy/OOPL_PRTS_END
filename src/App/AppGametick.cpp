#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>

void App::GameTick() {
    for(size_t i = 0; i< Enemies.size(); i++) {
        if(Enemies[i]->GetVisibility()) {
           Enemies[i]->Updatemove();
            if(Enemies[i]->GetPathPointsindex()>=Enemies[i]->GetPathPoints()->GetPointsize()) {
                m_map0107->EmenyEnterTower();
                Enemies[i]->SetVisible(false);
                Enemies[i]->SetLooping(false);
        }
        }

    }
}

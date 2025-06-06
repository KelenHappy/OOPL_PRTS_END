#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::backToLobby() {
    gametimer->Reset();
    gametimer->Pause();
    freeMap();
    m_level=level::lobby;
}

void App::freeMap() {
    m_0107.ClearGameObject();
    m_LevelCharacter.clear();
    Enemies.clear();
    m_FilmVector.clear();
}

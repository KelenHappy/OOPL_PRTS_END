#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::GameSecondTick() {
    m_map0107->Addmapcost(1);
    m_map0107->Update();
    m_Spawner->Update();

}

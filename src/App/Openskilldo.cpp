#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::OpenSkillOther(std::shared_ptr<AnimatedCharacter> Charater) {
    if(Charater->GetCharacterName()=="Myrtle") {

    }
    else if(Charater->GetCharacterName()=="Texas") {
        m_map0107->Addmapcost(12);
    }
}

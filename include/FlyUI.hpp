//
// Created by AaronChiu on 2025/4/15.
//

#ifndef FLYUI_HPP
#define FLYUI_HPP
#include "Character/AnimatedCharacter.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class FlyUI:public Util::GameObject {
    public:
    FlyUI() {
        m_Transform.scale={0.25,0.25};
    }
    void setnewcharacter(std::shared_ptr<AnimatedCharacter> Character) {
        m_Drawable = std::make_shared<Util::Image>(RESOURCE_DIR"/Character/"+Character->GetJob()+"/"+Character->GetCharacterName()+"/Idle/1.png");

    }
};


#endif //FLYUI_HPP

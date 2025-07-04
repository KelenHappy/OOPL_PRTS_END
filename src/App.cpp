#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::Update() {
    auto mouse=Util::Input::GetCursorPosition();
    if(Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
        std::cout <<std::to_string(mouse.x)<<" "<<std::to_string(mouse.y)<<std::endl;
    }
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
       Util::Input::IfExit()) {
        m_CurrentState = State::END;}
    if (gametimer->HasElapsed(40)) { // 每 50 毫秒執行一次
        gametimer->Reset();
        GameTick();
        Tickcount++;
        if (Tickcount >=20) {Tickcount=0;GameSecondTick();}
    }
    if(m_level==level::lobby){
        // BGM
        PlayBGM(RESOURCE_DIR"/music/LOBBY.mp3");
        choicemap();
        m_Root.Update();
    }
    else if(m_level==level::main17) {
        // BGM
        PlayBGM(RESOURCE_DIR"/music/1-7.mp3");

        LevelMain17();
	}
    else if(m_level==level::cc5) {
        // BGM
        PlayBGM(RESOURCE_DIR"/music/競技場1.mp3");
        LevelMain17();
    }
    else if(m_level==level::rog53) {
        // BGM
        PlayBGM(RESOURCE_DIR"/music/競技場2.mp3");

        LevelMain17();
    }
    else if(m_level==level::chooseCharacter) {
        PlayBGM(RESOURCE_DIR"/music/失控.mp3");

        ChooseCharacter();
    }
    else if(m_level==level::loading) {
        m_Loading.Update();
        switch (m_MainScream->GetMapchoice()) {
            case Mapchoice::main17:
                MapStart();
                m_level=level::main17;
            break;
            case Mapchoice::cc5:
                MapStart();
                m_level=level::cc5;
            break;
            case Mapchoice::rog53:
                MapStart();
                m_level=level::rog53;
            break;
            default:
                break;
        }
    }
    else if(m_level==level::chooseCharacter) {
        ChooseCharacter();
    }
    else if(m_level==level::BackToLobby) {
        m_Loading.Update();
        backToLobby();
    }
}


void App::Debug() {
    auto mouse =Util::Input::GetCursorPosition(); Util::Input::GetCursorPosition();
    Util::Transform mouseT;
    mouseT.translation = mouse;

    if (Util::Input::IsKeyDown(Util::Keycode::KP_ENTER)) {
        for (size_t i = 0; i < m_map0107->Getblock().size(); i++) {
            if (!m_map0107->Getblock()[i]) {
                std::cerr << "Warning: Block[" << i << "] is nullptr!" << std::endl;
                continue;
            }
            LOG_DEBUG(m_map0107->Getblock()[i]->m_Transform.translation);
        }
    }

    if (Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
        // 點到 Card
		
        for (size_t i = 0; i < m_map0107->GetCard().size(); ++i) {
            if (!m_map0107->GetCard()[i]) continue;  // 避免 nullptr 存取
            if (checkCollisionNearMouse(mouseT, m_map0107->GetCard()[i]->m_Transform, 50)) {
                m_CardCarry = i;
                if(m_LevelCharacter[m_CardCarry]->GetState() == CharacterState::Default){
                    CheckCard = true;
                    m_map0107->openMapblock(m_map0107->GetCard()[m_CardCarry]->GetCharacter()->GetBlockState());
                    m_flyUI->setnewcharacter(m_map0107->GetCard()[i]->GetCharacter());}
                std::cout << m_CardCarry << std::endl;
                break;
            }
        }
        // 點到 Block
        if(CheckCard==true){
            for (size_t i = 0; i < m_map0107->Getblock().size(); ++i) {
                if (!m_map0107->Getblock()[i]) continue;  // 避免 nullptr 存取
                if (checkCollisionNearMouse(mouseT, m_map0107->Getblock()[i]->m_Transform, 40)) {
                    m_Carry = i;
                    carry = true;
                    break;
                }
            }
        }
		//點到角色
		for (size_t i = 0; i < m_LevelCharacter.size(); ++i) {
            if (checkCollision(mouse, m_LevelCharacter[i]->GetPositionFix(), 30,30)
			and m_LevelCharacter[i]->GetState() != CharacterState::Default) {
                m_CharacterCarry = i;
                CheckCharacter = true;
                //std::cout<<carry<<" "<<CheckCard<<" "<<CheckCharacter<<" "<<m_LevelCharacter[m_CharacterCarry]->GetVisibility()<<" "<<std::endl;
                break;
            }
        }
    }

}




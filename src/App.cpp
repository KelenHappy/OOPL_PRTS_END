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
        LOG_DEBUG(std::to_string(mouse.x)+" "+std::to_string(mouse.y));
    }
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
       Util::Input::IfExit()) {
        m_CurrentState = State::END;}
    if (gametimer->HasElapsed(40)) { // 每 50 毫秒執行一次
        GameTick();
        Tickcount++;
        if (Tickcount >=20) {Tickcount=0;GameSecondTick();}
        gametimer->Reset();
    }
    if(m_level==level::lobby){
        if(Util::Input::IsKeyDown(Util::Keycode::Q)) {
            m_level=level::main17;
            Map0107Loading();
        }
		else if(Util::Input::IsKeyDown(Util::Keycode::C)){
			m_level=level::chooseCharacter;
		}
        choicemap();
        m_Root.Update();
    }
    else if(m_level==level::main17) {
        LevelMain17();
		Debug();
	}
    else if(m_level==level::chooseCharacter) {
        ChooseCharacter();
    }
    else if(m_level==level::loading) {
        m_Loading.Update();
        switch (m_MainScream->GetMapchoice()) {
            case Mapchoice::main17:
                Map0107Loading();
                m_level=level::main17;
            break;
            case Mapchoice::cc5:
                Map0107Loading();
                m_level=level::cc5;
            break;
            case Mapchoice::rog53:
                Map0107Loading();
                m_level=level::rog53;
            break;
            default:
                break;
        }
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




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
    if (gametimer->HasElapsed(50)) { // 每 50 毫秒執行一次
        GameTick();
        gametimer->Reset();
    }
    if(m_level==level::lobby){
        if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
            Util::Input::IfExit()) {
            m_CurrentState = State::END;
        }
        if(Util::Input::IsKeyDown(Util::Keycode::Q)) {
            m_level=level::main17;
            Map0107Loading();
        }
        m_Root.Update();
    }
    else if(m_level==level::main17) {

        if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
            m_CurrentState = State::END;
        }
        LevelMain17();
		Debug();
	}
}


// 計算兩個座標之間的距離
double App::calculateDistance(Util::Transform a, Util::Transform b) {
    return sqrt((a.translation.x - b.translation.x) * (a.translation.x - b.translation.x) + (a.translation.y - b.translation.y) * (a.translation.y - b.translation.y));
}

// 檢查滑鼠座標與物品座標之間的距離是否小於等於 range
bool App::checkCollisionNearMouse(Util::Transform Mouse, Util::Transform Item, int range) {
    double distance = calculateDistance(Mouse, Item);
    return distance <= range;
}
void App::Debug() {

    auto mouse = Util::Input::GetCursorPosition();
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
                CheckCard = true;
                m_CardCarry = i;
				std::cout << m_CardCarry << std::endl;
                break;
            }
        }
        // 點到 Block
        for (size_t i = 0; i < m_map0107->Getblock().size(); ++i) {
            if (!m_map0107->Getblock()[i]) continue;  // 避免 nullptr 存取
            if (checkCollisionNearMouse(mouseT, m_map0107->Getblock()[i]->m_Transform, 45)) {
                m_Carry = i;
                carry = true;
                break;
            }
        }
		//點到角色
		for (size_t i = 0; i < m_StartCharacter.size(); ++i) {
            if (checkCollisionNearMouse(mouseT, m_StartCharacter[i]->m_Transform, 35)) {
                m_CharacterCarry = i;
                CheckCharacter = true;
                break;
            }
        }
    }

}

void App::GameTick() {


}



#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>


void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;
    m_MainScream= std::make_shared<MainScream>();
    m_TT = std::make_shared<TextBox>();
    m_Root.AddChildren(m_MainScream->GetChildren());
    m_map0107=std::make_shared<Map>();
    m_0107.AddChildren(m_map0107->GetChildren());
}

void App::Update() {
    auto mouse=Util::Input::GetCursorPosition();
    /*if(Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
        //LOG_DEBUG(std::to_string(mouse.x)+" "+std::to_string(mouse.y));


    }*/
    if(m_level==level::lobby){
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
    if(Util::Input::IsKeyDown(Util::Keycode::Q)) {
        m_level=level::main17;
    }
    m_Root.Update();
    }
    else if(m_level==level::main17) {
        if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
            m_CurrentState = State::END;
        }
        Debug();
        m_0107.Update();
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
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
    auto mouse=Util::Input::GetCursorPosition();
    Util::Transform mouseT;
    mouseT.translation=mouse;
    if(Util::Input::IsKeyDown(Util::Keycode::KP_ENTER)) {
        for(int i=0;i<m_map0107->Getblock().size();i++) {
            LOG_DEBUG( m_map0107->Getblock()[i]->m_Transform.translation);
        }
    }
    if(Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
        if(carry==false) {
            carry=false;
            for(int i=0;i<m_map0107->Getblock().size();i++) {
                if(checkCollisionNearMouse( mouseT,m_map0107->Getblock()[i]->m_Transform, 30)) {
                    m_Carry=i;
                    carry=true;
                    LOG_DEBUG("carry ");
                }
            }
            if(carry==false) {
                m_Carry=-1;
            }
        }
        else {carry=false;}
    }
    if(carry) {
        m_map0107->Getblock()[m_Carry]->m_Transform.translation=mouse;
    }


}


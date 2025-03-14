#include "App.hpp"

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
    if(Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
        LOG_DEBUG(std::to_string(mouse.x)+" "+std::to_string(mouse.y));
        // LOG_DEBUG(std::to_string(m_MainScream->GetScaledSize().x)+" "+std::to_string(m_MainScream->GetScaledSize().y));
    }
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
        m_0107.Update();
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}

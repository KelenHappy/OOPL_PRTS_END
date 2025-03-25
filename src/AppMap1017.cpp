#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::LevelMain17() {
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
			m_CurrentState = State::END;
        }
    //Debug();
	/*
	for (int i = 0; i < 1; ++i) {
			m_BugAs[i]->SetVisible(true);     
			m_BugAs[i]->SetLooping(true);     
			m_BugAs[i]->SetState(EnemyState::Move);
	}
	*/
    m_0107.Update();
}

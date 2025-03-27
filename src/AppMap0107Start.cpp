#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::Map0107Loading() {
    //加載敵人
	m_BugAs = std::vector<std::shared_ptr<BugA>>();
	m_BugAs.resize(15);
	for (int i = 0; i < 10; ++i) {
		m_BugAs[i] = std::make_shared<BugA>();
		m_BugAs[i]->SetPosition({m_BugAs[i]->GetPosition().x, m_BugAs[i]->GetPosition().y + i*30.0f});
		m_BugAs[i]->SetZIndex(10);
		m_BugAs[i]->SetVisible(true);     
		m_BugAs[i]->SetLooping(true);
		m_0107.AddChild(m_BugAs[i]);
	}
	m_Sussurro->SetState(CharacterState::Default);
	m_Sussurro->SetLooping(true);
	m_0107.AddChild(m_Sussurro);
	
}

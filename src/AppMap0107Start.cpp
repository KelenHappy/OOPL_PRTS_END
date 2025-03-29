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
	m_BugAs.resize(12);
	for (size_t i = 0; i < 10; ++i) {
		m_BugAs[i] = std::make_shared<BugA>();
		m_BugAs[i]->SetPosition({m_BugAs[i]->GetPosition().x, m_BugAs[i]->GetPosition().y + i*30.0f});
		m_BugAs[i]->SetZIndex(10);
		m_BugAs[i]->SetImageSize(0.8f,0.8f);
		m_BugAs[i]->SetVisible(false);     
		m_BugAs[i]->SetLooping(false);
		m_0107.AddChild(m_BugAs[i]);
	}
	//角色選則
	for (size_t i = 0; i < m_StartCharacter.size(); ++i) {
		m_StartCharacter[i]->SetState(CharacterState::Default);
		m_StartCharacter[i]->SetLooping(true);
		m_StartCharacter[i]->SetImageSize(0.8f, 0.8f);
		m_StartCharacter[i]->SetPosition({575 - i*150, -289});
		m_0107.AddChild(m_StartCharacter[i]);
	}
}

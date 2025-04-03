#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::Map0107Loading() {
    //加載敵人
	m_BugAs.reserve(50);
	m_BugAs.resize(7);
	for (int i = 0; i < 7; ++i) {
		m_BugAs[i] = std::make_shared<BugA>();
		m_BugAs[i]->SetZIndex(10);
		m_BugAs[i]->SetImageSize(0.5f,0.5f);
		m_BugAs[i]->SetVisible(false);     
		m_BugAs[i]->SetLooping(false);
		m_0107.AddChild(m_BugAs[i]);
	}

	m_Soldiers = std::vector<std::shared_ptr<Soldier>>();
	m_Soldiers.resize(5);
	for (size_t i = 0; i < 5; ++i) {
		m_Soldiers[i] = std::make_shared<Soldier>();
		m_Soldiers[i]->SetZIndex(10);
		m_Soldiers[i]->SetImageSize(0.5f,0.5f);
		m_Soldiers[i]->SetVisible(false);     
		m_Soldiers[i]->SetLooping(false);
		m_0107.AddChild(m_Soldiers[i]);
	}

	
	m_Throwers = std::vector<std::shared_ptr<Thrower>>();
	m_Throwers.resize(2);
	for (size_t i = 0; i < 2; ++i) {
		m_Throwers[i] = std::make_shared<Thrower>();
		m_Throwers[i]->SetZIndex(10);
		m_Throwers[i]->SetImageSize(0.5f,0.5f);
		m_Throwers[i]->SetVisible(false);     
		m_Throwers[i]->SetLooping(false);
		m_0107.AddChild(m_Throwers[i]);
	}
	
	m_Varlorants = std::vector<std::shared_ptr<Varlorant>>();
	m_Varlorants.resize(1);
	for(size_t i = 0;i < 1; ++i){
		m_Varlorants[i] = std::make_shared<Varlorant>();
		m_Varlorants[i]->SetZIndex(10);
		m_Varlorants[i]->SetImageSize(0.5f,0.5f);
		m_Varlorants[i]->SetVisible(false);     
		m_Varlorants[i]->SetLooping(false);
		m_0107.AddChild(m_Varlorants[i]);
	}
	//角色選則

	for (size_t i = 0; i < m_StartCharacter.size(); ++i) {
		m_StartCharacter[i]->SetState(CharacterState::Default);
		m_StartCharacter[i]->SetLooping(false);
		m_StartCharacter[i]->SetVisible(false);
		m_StartCharacter[i]->SetImageSize(0.34f, 0.34f);
		m_StartCharacter[i]->SetPosition({575 - i*150, -289});
		std::shared_ptr<Card> cd=std::make_shared<Card>(m_StartCharacter[i]);
		cd->SetTranform(570-(i*144),-300);
		m_map0107->AddCard(cd);
		m_0107.AddChildren(m_map0107->GetChildrenCard());
		m_0107.AddChild(m_StartCharacter[i]);
	}
	gametimer->Start();
}

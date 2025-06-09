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
	m_flyUI=std::make_shared<FlyUI>();
	m_LoadingPage=std::make_shared<CreateIMG>("/MainScream/Loading.png",100);
	m_Loading.AddChild(m_LoadingPage);
	m_MainScream= std::make_shared<MainScream>();
	m_ChosenCharacter = std::make_shared<ChosenCharacter>();
    m_Root.AddChildren(m_MainScream->GetChildren());
    gametimer=std::make_shared<GameTimer>();
	m_placeUI=std::make_shared<PlaceUI>();


	//m_Root.AddChildren();


	// 角色擁有
	m_HalfCardScreen.AddChildren(m_ChosenCharacter->GetChildren());
	m_ChosenCharacter->CreateNewCharacter();
	m_ChosenCharacter->Settran();
	m_HalfCardScreen.AddChildren(m_ChosenCharacter->GetChildrenCard());
}

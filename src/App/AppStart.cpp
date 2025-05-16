#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>

#include "Video/VideoGameObject.hpp"
void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;
	m_flyUI=std::make_shared<FlyUI>();
	m_0107.AddChild(m_flyUI);
	m_LoadingPage=std::make_shared<CreateIMG>("/MainScream/Loading.png",100);
	m_Loading.AddChild(m_LoadingPage);
	m_MainScream= std::make_shared<MainScream>();
	m_ChosenCharacter = std::make_shared<ChosenCharacter>();
    m_Root.AddChildren(m_MainScream->GetChildren());
    gametimer=std::make_shared<GameTimer>();
	//m_Root.AddChildren();

    // Character
	//std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont
	/*
	void SetInfo(int SetTime, int SetCost, float AttackTime, int Health, int Attack, int Defend, int DefendMagic,
    int SkillDefault, int SkillCost, float SkillTime, std::string skillinfo, std::string skillname,
	defendlevel
	*/
	// 角色擁有
	m_HalfCardScreen.AddChildren(m_ChosenCharacter->GetChildren());
	m_ChosenCharacter->CreateNewCharacter();
	m_ChosenCharacter->Settran();
	m_HalfCardScreen.AddChildren(m_ChosenCharacter->GetChildrenCard());
	//test
	std::shared_ptr<Util::VideoGameObject> test = std::make_shared<Util::VideoGameObject>();
	m_Root.AddChild(test);
	test->LoadVideo(RESOURCE_DIR"/Character/Caster/Ceobe/Attack-x1.webm");
	test->Play();
}

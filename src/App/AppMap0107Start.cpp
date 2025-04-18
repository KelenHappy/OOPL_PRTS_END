#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::Map0107Loading() {
    //加載敵人
	m_Spawner=std::make_shared<Spawner>();
	Enemies=m_Spawner->GetEnemies();
	m_0107.AddChildren(m_Spawner->GetEnemiesGameobject());
	//角色選則

	for (size_t i = 0; i < m_StartCharacter.size(); ++i) {
		std::cout << "Get In Character" << m_StartCharacter[i]->GetCharacterName() << std::endl;
		m_StartCharacter[i]->CreateAnimation();
		m_StartCharacter[i]->SetZIndex(15);
		m_StartCharacter[i]->SetState(CharacterState::Default);
		m_StartCharacter[i]->SetLooping(false);
		m_StartCharacter[i]->SetVisible(false);
		m_StartCharacter[i]->SetImageSize(0.32f, 0.32f);
		m_StartCharacter[i]->SetPosition({575 - i*150, -289});
		std::shared_ptr<Card> cd=std::make_shared<Card>(m_StartCharacter[i]);
		cd->SetTranform(570-(i*144),-300);
		m_map0107->AddCard(cd);
		m_0107.AddChildren(m_map0107->GetChildrenCard());
		m_0107.AddChild(m_StartCharacter[i]);
		m_0107.AddChild(m_StartCharacter[i]->Gethpbar());
	}
	gametimer->Start();
}

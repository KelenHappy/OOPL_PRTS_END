#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::ChooseCharacter() {
    //選擇角色
	for(size_t i = 0; i < m_StartCharacter.size(); i++){
		m_StartCharacter[i]->SetState(CharacterState::HalfCard);
		
	}
	
	m_HalfCardScreen.Update();
}

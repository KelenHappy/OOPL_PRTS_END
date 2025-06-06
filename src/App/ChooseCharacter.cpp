#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::ChooseCharacter() {
    //選擇角色
	if(Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
		std::vector<std::shared_ptr<HalfCard>> choiceitems=m_ChosenCharacter->GetHalfCard();
		for(size_t i=0;i<choiceitems.size();i++) {
			if(checkCollision(Util::Input::GetCursorPosition(),choiceitems[i]->m_Transform.translation,50,100)) {
				int n=choiceitems[i]->Getchoseindex();
				if (n==-1) {
					if (m_ChosenCharacter->GetChoiceCard().size()<12) {
						m_ChosenCharacter->AddChoiceCharacter(choiceitems[i]);
						choiceitems[i]->Setchoseindex(int(m_ChosenCharacter->GetChoiceCard().size()));
					}
				}
				else {
					choiceitems[i]->Setchoseindex(-1);
					m_ChosenCharacter->RemoveChoiceCharacter(n);
				}
			}
		}
		if(checkCollision(Util::Input::GetCursorPosition(),m_ChosenCharacter->GetExit()->m_Transform.translation,20,30)) {
			m_level=level::lobby;
		}
		if(checkCollision(Util::Input::GetCursorPosition(),m_ChosenCharacter->GetStart()->m_Transform.translation,50,100)) {
			m_LevelCharacter=m_ChosenCharacter->GetChoiceCharacter();
			m_level=level::loading;
			m_Loading.Update();
		}
	}

	m_HalfCardScreen.Update();
}

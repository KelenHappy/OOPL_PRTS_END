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
	if (Util::Input::IsKeyUp(Util::Keycode::M)){
		m_map0107->Addmapcost(99);
		for(size_t i = 0 ;i<m_LevelCharacter.size();i++) {
			m_LevelCharacter[i]->AddSkillCost(100);
			if(m_LevelCharacter[i]->GetDie())m_LevelCharacter[i]->DeDieCost(100);
		}
		m_map0107->UpdateCardLine();
    }

	/*if(carry == true and CheckCard == true) {
		// SetPosition
		if(m_LevelCharacter[m_CardCarry]->GetBlockState() == m_map0107->Getblock()[m_Carry]->GetBlockState() and 
		m_LevelCharacter[m_CardCarry]->GetState() == CharacterState::Default and m_LevelCharacter[m_CardCarry]->GetHealthRecover() > 0 and
		m_map0107->Getblock()[m_Carry]->HaveCharacter==false)
			{
			if(m_map0107->Takemapcost(m_LevelCharacter[m_CardCarry]->GetSetCost())) {
				m_LevelCharacter[m_CardCarry]->PlaceCharacter(m_map0107->Getblock()[m_Carry],m_CardCarry);
				m_LevelCharacter[m_CardCarry]->SetAttackRangeDefault(m_map0107->ExtractBlocksFromPattern(m_LevelCharacter[m_CardCarry]->GetDefaultRange(),m_map0107->Getblock()[m_Carry]->GetX(),m_map0107->Getblock()[m_Carry]->GetY(),Direction::NORTH));

				m_map0107->closeMapblock();
				m_flyUI->SetVisible(false);
			}
		}
		m_map0107->closeMapblock();
		m_flyUI->SetVisible(false);
		CheckCard = false;
		carry = false;
		m_Carry = -1;
		m_CardCarry = -1;
	}
	else if(carry == false and CheckCard == true 
	and m_LevelCharacter[m_CardCarry]->GetState() == CharacterState::Default){
		m_flyUI->m_Transform.translation=Util::Input::GetCursorPosition()+glm::vec2(0,250*0.13);
		m_flyUI->SetVisible(true);
		
	}
	else if(carry == false and CheckCard == false 
	and CheckCharacter and m_LevelCharacter[m_CharacterCarry]->GetVisibility()){
		// 收回角色
		m_LevelCharacter[m_CharacterCarry]->OutPlaceCharacter();
		m_map0107->closeMapblock();
		m_LevelCharacter[m_CharacterCarry]->showrange();
		m_Carry = -1;
		carry = false;
		m_CharacterCarry = -1;
		CheckCharacter = false;
	}
	else{
		CheckCharacter = false;
		CheckCard = false;
		carry = false;
		m_Carry = -1;
		m_CardCarry = -1;	
		m_CharacterCarry = -1;
	}*/
	ClickOfMap();
	if (m_map0107->EndAnimeUpdate()) {
		m_LoadingPage->SetNewIMGstd("/Maps/BackToLobby.png");
		m_level=level::BackToLobby;
		m_Loading.Update();


	}
	// 設定角色出現與否

	
    m_0107.Update();
}

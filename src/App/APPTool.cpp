#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>

void App::choicemap() {
    if(Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
        std::vector<std::shared_ptr<Util::GameObject>> choiceitems=m_MainScream->GetTextInfo();

        for(size_t i=0;i<choiceitems.size();i++) {
            if(checkCollision(Util::Input::GetCursorPosition(),choiceitems[i]->m_Transform.translation,110,20)) {
                if(i==0) {
                    m_level=level::chooseCharacter;
                }
                else if (i >= 1 && i <= 3) {
                    static constexpr Mapchoice maps[] = {Mapchoice::main17, Mapchoice::cc5, Mapchoice::rog53};
                    m_MainScream->SetMap(maps[i-1]);
                    std::string st[]={"主線1-7","八號競技場","緊急失控"};
                    m_ChosenCharacter->ChangeMaps(st[i-1]);
                }
            }
        }
    }


}
bool App::checkCollision(glm::vec2 cursorPos, glm::vec2 itemPos, float rangeX, float rangeY) {
    // 計算 X 軸和 Y 軸的距離
    float dx = abs(cursorPos.x - itemPos.x);
    float dy = abs(cursorPos.y - itemPos.y);
    // 檢查是否在矩形範圍內
    return (dx <= rangeX) && (dy <= rangeY);
}

// 計算兩個座標之間的距離
double App::calculateDistance(Util::Transform a, Util::Transform b) {
    return sqrt((a.translation.x - b.translation.x) * (a.translation.x - b.translation.x) + (a.translation.y - b.translation.y) * (a.translation.y - b.translation.y));
}

// 檢查滑鼠座標與物品座標之間的距離是否小於等於 range
bool App::checkCollisionNearMouse(Util::Transform Mouse, Util::Transform Item, int range) {
    double distance = calculateDistance(Mouse, Item);
    return distance <= range;
}
void App::DeBug2() {
    auto mouse=Util::Input::GetCursorPosition();
    Util::Transform mouseT;
    mouseT.translation=mouse;
    if(Util::Input::IsKeyDown(Util::Keycode::KP_ENTER)) {
        for(int i=0;i<m_map0107->Getblock().size();i++) {
            LOG_DEBUG( m_map0107->Getblock()[i]->m_Transform.translation);
        }
    }
    if(Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
        if(carry==false) {
            carry=false;
            for(int i=0;i<m_map0107->Getblock().size();i++) {
                if(checkCollisionNearMouse( mouseT,m_map0107->Getblock()[i]->m_Transform, 30)) {
                    m_Carry=i;
                    carry=true;
                    LOG_DEBUG("carry ");
                }
            }
            if(carry==false) {
                m_Carry=-1;
            }
        }
        else {carry=false;}
    }
    if(carry) {
        m_map0107->Getblock()[m_Carry]->m_Transform.translation=mouse;
    }

}

void App::ClickOfMap(){
    auto mouse =Util::Input::GetCursorPosition();
    if (Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
        Util::Transform mouseT;
        mouseT.translation = mouse;
        clicking=true;
        // 點到 Card
        if(m_UIMapLevel==UIMapLevel::Clickcard||m_UIMapLevel==UIMapLevel::Main){
            for (size_t i = 0; i < NowMap->GetCard().size(); ++i) {
                if (!NowMap->GetCard()[i]) continue;  // 避免 nullptr 存取
                if (checkCollisionNearMouse(mouseT, NowMap->GetCard()[i]->m_Transform, 50) and !NowMap->GetCard()[i]->GetCharacter()->GetVisibility()) {
                    m_CardCarry = i;
                    if(m_LevelCharacter[m_CardCarry]->GetState() == CharacterState::Default){
                        CheckCard = true;
                        NowMap->openMapblock(NowMap->GetCard()[m_CardCarry]->GetCharacter()->GetBlockState());
                        m_flyUI->setnewcharacter(NowMap->GetCard()[i]->GetCharacter());}
                    std::cout << m_CardCarry << std::endl;
                    break;
                }
            }
        }
        // 點到 Block
        if(m_UIMapLevel==UIMapLevel::Clickcard){
            for (size_t i = 0; i < NowMap->Getblock().size(); ++i) {
                if (!NowMap->Getblock()[i]) continue;  // 避免 nullptr 存取
                if (checkCollisionNearMouse(mouseT, NowMap->Getblock()[i]->m_Transform, 40)) {
                    m_Carry = i;
                    carry = true;
                    break;
                }
            }
        }
        //點到角色
        for (size_t i = 0; i < m_LevelCharacter.size(); ++i) {
            if (checkCollision(mouse, m_LevelCharacter[i]->GetPositionFix(), 30,30)
            and m_LevelCharacter[i]->GetState() != CharacterState::Default) {
                m_CharacterCarry = i;
                CheckCharacter = true;
                break;
            }
        }
    }
    Direction Dir;
    switch (m_UIMapLevel) {
        case UIMapLevel::Main:
            if(CheckCard == true) {
                m_UIMapLevel=UIMapLevel::Clickcard;
                ResetMapChoice();
            }
        else if (CheckCharacter) {
            m_UIMapLevel=UIMapLevel::ClickCharacter;
            m_LevelCharacter[m_CharacterCarry]->showrange();
            m_placeUI->setnewcharacterskill(m_LevelCharacter[m_CharacterCarry]);
            m_placeUI->SetPostion(m_LevelCharacter[m_CharacterCarry]->GetPositionFix().x,m_LevelCharacter[m_CharacterCarry]->GetPositionFix().y);
            m_placeUI->openUI(1);
            ResetMapChoice();
        }


            break;

        case UIMapLevel::Clickcard:
            m_flyUI->m_Transform.translation=Util::Input::GetCursorPosition()+glm::vec2(0,250*0.13);
            m_flyUI->SetVisible(true);
            if(clicking) {
                if(carry&&m_LevelCharacter[m_CardCarry]->GetBlockState() == m_map0107->Getblock()[m_Carry]->GetBlockState()&&m_LevelCharacter[m_CardCarry]->GetState() == CharacterState::Default and m_LevelCharacter[m_CardCarry]->GetHealthRecover() > 0 and
                    m_map0107->Getblock()[m_Carry]->HaveCharacter==false) {
                    if(m_map0107->Getmapcost()>=m_LevelCharacter[m_CardCarry]->GetSetCost()){
                    m_placeUI->openUI(0);
                    m_placeUI->SetPostion(m_map0107->Getblock()[m_Carry]->m_Transform.translation.x,m_map0107->Getblock()[m_Carry]->m_Transform.translation.y);
                    m_flyUI->m_Transform.translation=m_map0107->Getblock()[m_Carry]->m_Transform.translation+glm::vec2(0,250*0.13);
                    m_UIMapLevel=UIMapLevel::ChoiceDirection;
                        }
                    }
                ResetMapChoice();
                if(m_UIMapLevel!=UIMapLevel::ChoiceDirection) {
                    m_UIMapLevel=UIMapLevel::Main;
                    m_flyUI->SetVisible(false);
                    m_map0107->closeMapblock();
                }
            }

        break;

        case UIMapLevel::ChoiceDirection:
            // 選擇方向的畫面
                Dir= m_placeUI->NewDirection(mouse);
                if(Dir!=m_Direction) {
                    m_Direction=Dir;
                    m_map0107->closeMapblock();
                    if(Dir!=Direction::CENTER){
                      std::vector<std::shared_ptr<Block>> AttackRange=m_map0107->ExtractBlocksFromPattern(m_LevelCharacter[m_CardCarry]->GetDefaultRange(),m_map0107->Getblock()[m_Carry]->GetX(),m_map0107->Getblock()[m_Carry]->GetY(),Dir) ;
                        for(size_t i=0;i<AttackRange.size();i++) {
                            AttackRange[i]->SetVisible(true);
                            AttackRange[i]->ChangeImage("/Maps/Attackrange.png");
                        }
                    }
                }
                if(clicking) {
                    if(checkCollision(Util::Input::GetCursorPosition(),m_placeUI->Getback()->m_Transform.translation,30,30)) {
                        m_placeUI->closeUI();
                        m_map0107->closeMapblock();
                        m_flyUI->SetVisible(false);
                        m_UIMapLevel=UIMapLevel::Main;
                    }
                    else if(Dir!=Direction::CENTER) {
                        m_UIMapLevel=UIMapLevel::Main;//放置
                       if( m_map0107->Takemapcost(m_LevelCharacter[m_CardCarry]->GetPlaceCostNum())){
                        m_LevelCharacter[m_CardCarry]->PlaceCharacter(m_map0107->Getblock()[m_Carry],m_CardCarry);
                        m_LevelCharacter[m_CardCarry]->SetAttackRangeDefault(m_map0107->ExtractBlocksFromPattern(m_LevelCharacter[m_CardCarry]->GetDefaultRange(),m_map0107->Getblock()[m_Carry]->GetX(),m_map0107->Getblock()[m_Carry]->GetY(),Dir));
                        m_map0107->closeMapblock();
                        m_map0107->UpdateCardLine();
                        m_flyUI->SetVisible(false);
                        m_placeUI->closeUI();
                       }
                    }
                    ResetMapChoice();
                }
                break;


        case UIMapLevel::ClickCharacter:
            // 點選角色的畫面
                m_placeUI->UpdateUI(m_LevelCharacter[m_CharacterCarry]);
                if(clicking and !m_LevelCharacter[m_CharacterCarry]->GetDie()) {
                    if(checkCollision(Util::Input::GetCursorPosition(),m_placeUI->Getskill()->m_Transform.translation,30,30)) {
                        if ( !m_LevelCharacter[m_CharacterCarry]->GetSkillOpen() and m_LevelCharacter[m_CharacterCarry]->GetVisibility() and m_LevelCharacter[m_CharacterCarry]->GetSkillCost() <= m_LevelCharacter[m_CharacterCarry]->GetSkillNow()) {
                            m_LevelCharacter[m_CharacterCarry]->OpenSkill();
                            m_LevelCharacter[m_CharacterCarry]->SetAttackRangeDefault(
                                m_map0107->ExtractBlocksFromPattern(m_LevelCharacter[m_CharacterCarry]->GetDefaultRange(),
                                m_LevelCharacter[m_CharacterCarry]->GetPlaceBlock()->GetX(),
                                m_LevelCharacter[m_CharacterCarry]->GetPlaceBlock()->GetY(),
                                m_LevelCharacter[m_CharacterCarry]->GetDirection()));
                            std::cout << m_LevelCharacter[m_CharacterCarry]->GetCharacterName() << " Open Skill" << std::endl;
                        }
                    }
                    else if(checkCollision(Util::Input::GetCursorPosition(),m_placeUI->Getback()->m_Transform.translation,30,30)){
                        m_map0107->Addmapcost(m_LevelCharacter[m_CharacterCarry]->GetPlaceCostNum()*0.5);
                        m_LevelCharacter[m_CharacterCarry]->OutPlaceCharacter();
                        m_map0107->UpdateCardLine();
                    }
                    m_placeUI->closeUI();
                    ResetMapChoice();
                    m_map0107->closeMapblock();
                    m_UIMapLevel=UIMapLevel::Main;
                }


                break;

        default:
            // 預設處理（可選）

                break;
    }
}
void App::ResetMapChoice() {
    clicking=false;
    CheckCard = false;
    carry=false;
    CheckCharacter = false;
}

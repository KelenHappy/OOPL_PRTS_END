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
                    m_level=level::loading;
                    m_Loading.Update();
                }
                else if (i >= 1 && i <= 3) {
                    static constexpr Mapchoice maps[] = {Mapchoice::main17, Mapchoice::cc5, Mapchoice::rog53};
                    m_MainScream->SetMap(maps[i-1]);
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
    if (Util::Input::IsKeyDown(Util::Keycode::MOUSE_LB)) {
        auto mouse =Util::Input::GetCursorPosition();
        Util::Transform mouseT;
        mouseT.translation = mouse;
        // 點到 Card
        for (size_t i = 0; i < NowMap->GetCard().size(); ++i) {
            if (!NowMap->GetCard()[i]) continue;  // 避免 nullptr 存取
            if (checkCollisionNearMouse(mouseT, NowMap->GetCard()[i]->m_Transform, 50)) {
                m_CardCarry = i;
                if(m_LevelCharacter[m_CardCarry]->GetState() == CharacterState::Default){
                    CheckCard = true;
                    NowMap->openMapblock(NowMap->GetCard()[m_CardCarry]->GetCharacter()->GetBlockState());
                    m_flyUI->setnewcharacter(NowMap->GetCard()[i]->GetCharacter());}
                std::cout << m_CardCarry << std::endl;
                break;
            }
        }
        // 點到 Block
        if(CheckCard==true){
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
}

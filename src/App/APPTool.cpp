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

        for(int i=0;i<choiceitems.size();i++) {
            if(checkCollision(Util::Input::GetCursorPosition(),choiceitems[i]->m_Transform.translation,110,20)) {
                if(i==0) {
                    m_level=level::main17;
                    Map0107Loading();
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

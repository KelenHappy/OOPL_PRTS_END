#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>

std::vector<std::shared_ptr<Enemy> > App::GetCharaterEnemyinRange(std::shared_ptr<AnimatedCharacter> Charater) {
    std::vector<std::shared_ptr<Block> > Bk = Charater->GetAttackRangeNow();
    std::vector<std::shared_ptr<Enemy>> Emy;
    for (size_t i = 0; i < Enemies.size(); i++) {
        if (Enemies[i]->GetVisibility()) Emy.push_back(Enemies[i]);
    }

    std::vector<bool> BEmy(Emy.size(), false);

    int Range = 52;
    if (m_map0107->GetMapsize().x == 10) {
        Range *= 0.8;
    }

    for (auto B : Bk) {
        if (B->GetBlockState() == BlockState::GROUND || B->GetBlockState() == BlockState::NONE) {
            for (size_t i = 0; i < Emy.size(); i++) {
                if (checkCollision(B->m_Transform.translation, Emy[i]->GetPositionFix(), Range, Range)) {
                    BEmy[i] = true;
                }
            }
        }
    }

    std::vector<std::shared_ptr<Enemy>> Emy1;
    if (Charater->GetGotEnemy().size() > 0) {
        for (auto& enemy : Charater->GetGotEnemy()) {
            Emy1.push_back(enemy);  // 将每个元素添加到 Emy1
        }
    }

    for (size_t i = 0; i < Emy.size(); i++) {
        if (BEmy[i]) {
            Emy1.push_back(Emy[i]);
        }
    }

    return Emy1;
}
std::vector<std::shared_ptr<AnimatedCharacter>> App::GetCharaterinRange(std::shared_ptr<AnimatedCharacter> Charater) {
    std::vector<std::shared_ptr<Block> > Bk = Charater->GetAttackRangeNow();
    std::vector<std::shared_ptr<AnimatedCharacter>> CTR;
    for (size_t i = 0; i < m_LevelCharacter.size(); i++) {
        for (size_t j = 0; j < Bk.size(); j++) {
            if (Bk[j] == m_LevelCharacter[i]->GetPlaceBlock()) {
                CTR.push_back(m_LevelCharacter[i]);
            }
        }
    }
    return CTR;
}

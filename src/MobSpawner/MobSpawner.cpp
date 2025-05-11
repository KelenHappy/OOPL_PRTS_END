

#include "MobSpawner/MobSpawner.hpp"

#include <Enemy/DefendSoloSoldier.hpp>

#include "Enemy/BOSS.hpp"
#include "Enemy/BugA.hpp"
#include "Enemy/ColdBug.hpp"
#include "Enemy/ColdWolf.hpp"
#include "Enemy/ComplieMagic.hpp"
#include "Enemy/CrazyHostLeader.hpp"
#include "Enemy/CrazyHostThrower.hpp"
#include "Enemy/KingStudent.hpp"
#include "Enemy/NoNameSoldier.hpp"
#include "Enemy/SnowmanTeam.hpp"
#include "Enemy/Soldier.hpp"
#include "Enemy/SoldierStudent.hpp"
#include "Enemy/Thrower.hpp"
#include "Enemy/TraingMonster.hpp"
#include "Enemy/Varlorant.hpp"

Spawner::Spawner(Mapchoice Mc) {
    Time=0;
    index=0;
    CreateSpawner(Mc);

}
void Spawner::CreateSpawner(Mapchoice Mc) {
    switch (Mc) {
        case(Mapchoice::cc5):
            CreateEnemiesCC5();
        break;
        case(Mapchoice::main17):
            CreateEnemies0107();
        break;
        case(Mapchoice::rog53):
            CreateEnemiesRog53();
        break;
    }
}

std::shared_ptr<Enemy> Spawner::SpawnEnemy(Enemytype type) {
    std::shared_ptr<Enemy> Emy;
    switch (type) {
        case(Enemytype::Soldier):
            Emy = std::make_shared<Soldier>();
            break;
        case(Enemytype::Thrower):
            Emy = std::make_shared<Thrower>();
            break;
        case(Enemytype::Valorant):
            Emy = std::make_shared<Varlorant>();
            break;
        case(Enemytype::BugA):
            Emy = std::make_shared<BugA>();
            break;
        case(Enemytype::CrazyHostThrower):
            Emy = std::make_shared<CrazyHostThrower>();
            break;
        case(Enemytype::SnowmanTeam):
            Emy = std::make_shared<SnowmanTeam>();
            break;
        case(Enemytype::ColdWolf):
            Emy = std::make_shared<ColdWolf>();
            break;
        case(Enemytype::CrazyHostLeader):
            Emy = std::make_shared<CrazyHostLeader>();
            break;
        case(Enemytype::ColdBug):
            Emy = std::make_shared<ColdBug>();
            break;
        case(Enemytype::NoNameSoldier):
            Emy = std::make_shared<NoNameSoldier>();  // 注意 Soldier 拼寫是否正確
            break;
        case(Enemytype::TraingMonster):
            Emy = std::make_shared<TraingMonster>();  // 注意 Traing 拼寫是否正確 (可能是 Training)
            break;
        case(Enemytype::DefendSoloSoldier):
            Emy = std::make_shared<DefendSoloSoldier>();
            break;
        case(Enemytype::SoldierStudent):
            Emy = std::make_shared<SoldierStudent>();
            break;
        case(Enemytype::ComplieMagic):
            Emy = std::make_shared<ComplieMagic>();
            break;
        case(Enemytype::KingStudent):
            Emy = std::make_shared<KingStudent>();
            break;
        case(Enemytype::BOSS):
            Emy = std::make_shared<BOSS>();
            break;
        default:
            // 可以選擇拋出異常或返回空指針
            throw std::invalid_argument("Unknown enemy type");
            // 或者: return nullptr;
    }
    if (Emy) {  // 只有在成功創建敵人的情況下才設置屬性
        Emy->SetZIndex(10);
        Emy->SetImageSize(-0.22f, 0.22f);
        Emy->SetVisible(false);
        Emy->SetLooping(false);
    }

    return Emy;
}
void Spawner::AddSpawnEnemy(Enemytype type) {
    enemies.push_back(SpawnEnemy(type));
}
void Spawner::AddSpawn(float time, Enemytype type, int pathIndex) {
    SpawnInfo info = {time, type, pathIndex};

    // 使用 std::lower_bound 來找出插入位置
    auto it = std::lower_bound(spawnQueue.begin(), spawnQueue.end(), info,
        [](const SpawnInfo& a, const SpawnInfo& b) {
            return a.spawnTime < b.spawnTime;
        });

    spawnQueue.insert(it, info);
    AddSpawnEnemy(type);  // 加入敵人
}
void Spawner::Update() {
    if(index>=int(spawnQueue.size())) {return;}
    if(spawnQueue[index].spawnTime<Time) {
        enemies[index]->SetLooping(true);
        enemies[index]->SetPathPoint(paths[spawnQueue[index].pathIndex]);
        enemies[index]->m_Transform.translation=paths[spawnQueue[index].pathIndex]->GetStartPoint()+glm::vec2{0,250 *abs(enemies[index]-> m_Transform.scale.y)};
        enemies[index]->GetHpBar()->m_Transform.translation
        = enemies[index]->GetPositionFix()-glm::vec2{ 0,20 };
        if(enemies[index]->IfAnimationEnds())enemies[index]->SetState(EnemyState::Move);
        enemies[index]->SetVisible(true);
        enemies[index]->GetHpBar()->SetVisible(true);
        index++;
        Update();
    }
    else{
		Time++;
	}

}

Spawner::~Spawner() {

}


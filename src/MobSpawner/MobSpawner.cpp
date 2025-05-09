

#include "MobSpawner/MobSpawner.hpp"
#include "Enemy/BugA.hpp"
#include "Enemy/Soldier.hpp"
#include "Enemy/Thrower.hpp"
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
            Emy=std::make_shared<Soldier>();
            break;
        case(Enemytype::Thrower):
            Emy=std::make_shared<Thrower>();
            break;
        case(Enemytype::Valorant):
            Emy=std::make_shared<Varlorant>();
            break;
        case(Enemytype::BugA):
            Emy=std::make_shared<BugA>();
            break;
    }
    Emy->SetZIndex(10);
    Emy->SetImageSize(-0.3f,0.3f);
    Emy->SetVisible(false);
    Emy->SetLooping(false);
    return Emy;
}
void Spawner::AddSpawnEnemy(Enemytype type) {
    enemies.push_back(SpawnEnemy(type));
}
void Spawner::AddSpawn(float time, Enemytype type, int pathIndex) {
    spawnQueue.push_back({time, type, pathIndex});
    AddSpawnEnemy(type);
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


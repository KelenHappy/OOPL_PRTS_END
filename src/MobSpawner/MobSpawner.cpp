

#include "MobSpawner/MobSpawner.hpp"
#include "Enemy/BugA.hpp"
#include "Enemy/Soldier.hpp"
#include "Enemy/Thrower.hpp"
#include "Enemy/Varlorant.hpp"

Spawner::Spawner() {
    Time=0;
    index=0;
    std::vector<int> Waittime={-1,-1,-1,-1,-1,-1} ;
    std::vector<std::vector<glm::vec2>> allPaths = {
        {
            glm::vec2(488.0f, 202.0f),
            glm::vec2(-98.0f, 197.0f),
            glm::vec2(-103.0f, 116.0f),
            glm::vec2(-310.0f, 120.0f),
            glm::vec2(-324.0f, 28.0f),
            glm::vec2(-550.0f, 36.0f)
        },
        {
            glm::vec2(543.0f, 33.0f),
            glm::vec2(-108.0f, 34.0f),
            glm::vec2(-108.0f, 115.0f),
            glm::vec2(-309.0f, 116.0f),
            glm::vec2(-319.0f, 33.0f),
            glm::vec2(-550.0f, 36.0f)
        },
        {
            glm::vec2(548.0f, 33.0f),
            glm::vec2(-111.0f, 35.0f),
            glm::vec2(-117.0f, -67.0f),
            glm::vec2(-346.0f, -67.0f),
            glm::vec2(-324.0f, 32.0f),
            glm::vec2(-553.0f, 36.0f)
        },
        {
            glm::vec2(613.0f, -174.0f),
            glm::vec2(-122.0f, -177.0f),
            glm::vec2(-121.0f, -67.0f),
            glm::vec2(-342.0f, -63.0f),
            glm::vec2(-326.0f, 33.0f),
            glm::vec2(-550.0f, 36.0f)
        }
    };
    for (const auto& pathPoints : allPaths) {
        std::shared_ptr<PathPoints> path = std::make_shared<PathPoints>();
        path->setPoint(pathPoints);
        path->setWaitTime(Waittime);
        AddPath(path);
    }
    float currentTime = 0.0f;

    // 0
    AddSpawn(currentTime += 6.0f, Enemytype::BugA, 0); // x1
    // 1
    AddSpawn(currentTime += 1.0f, Enemytype::BugA, 3); // x2
    AddSpawn(currentTime += 1.0f, Enemytype::BugA, 3);

    // 2
    AddSpawn(currentTime += 5.0f, Enemytype::BugA, 1); // x2
    AddSpawn(currentTime += 1.0f, Enemytype::BugA, 1);

    // 3
    AddSpawn(currentTime += 5.0f, Enemytype::BugA, 0); // x2
    AddSpawn(currentTime += 1.0f,Enemytype::BugA, 0);

    // 4
    AddSpawn(currentTime += 7.0f, Enemytype::Valorant, 2); // x2
    AddSpawn(currentTime += 1.0f, Enemytype::Valorant, 2);

    // 5
    AddSpawn(currentTime += 7.0f, Enemytype::Soldier, 3); // x2
    AddSpawn(currentTime += 1.0f, Enemytype::Soldier, 3);

    // 6
    AddSpawn(currentTime += 15.0f, Enemytype::Thrower, 0); // x1

    // 7
    AddSpawn(currentTime += 1.0f, Enemytype::Thrower, 3); // x1

    // 8
    AddSpawn(currentTime += 3.0f, Enemytype::Soldier, 1); // x1

    // 9
    AddSpawn(currentTime += 3.0f, Enemytype::Soldier, 2); // x1

    // 10
    AddSpawn(currentTime += 9.0f, Enemytype::Valorant, 0); // x1

    // 11
    AddSpawn(currentTime += 0.0f, Enemytype::Valorant, 3); // x1 (同時間)

    // 12
    AddSpawn(currentTime += 6.0f, Enemytype::Soldier, 0); // x1
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


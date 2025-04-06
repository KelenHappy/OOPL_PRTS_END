#include <MobSpawner.hpp>

#include "Enemy/BugA.hpp"
#include "Enemy/Soldier.hpp"
#include "Enemy/Thrower.hpp"
#include "Enemy/Varlorant.hpp"

Spawner::Spawner() {
    std::vector<std::vector<glm::vec2>> allPaths = {
        {
            glm::vec2(-29.0f, -58.0f),
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
        AddPath(path);
    }
    float currentTime = 0.0f;

    // 0
    AddSpawn(currentTime += 6.0f, static_cast<int>(Enemytype::BugA), 0); // x1

    // 1
    AddSpawn(currentTime += 1.0f, static_cast<int>(Enemytype::BugA), 0); // x2
    AddSpawn(currentTime += 1.0f, static_cast<int>(Enemytype::BugA), 0);

    // 2
    AddSpawn(currentTime += 5.0f, static_cast<int>(Enemytype::BugA), 0); // x2
    AddSpawn(currentTime += 1.0f, static_cast<int>(Enemytype::BugA), 0);

    // 3
    AddSpawn(currentTime += 5.0f, static_cast<int>(Enemytype::BugA), 0); // x2
    AddSpawn(currentTime += 1.0f, static_cast<int>(Enemytype::BugA), 0);

    // 4
    AddSpawn(currentTime += 7.0f, static_cast<int>(Enemytype::Valorant), 0); // x2
    AddSpawn(currentTime += 1.0f, static_cast<int>(Enemytype::Valorant), 0);

    // 5
    AddSpawn(currentTime += 7.0f, static_cast<int>(Enemytype::Soldier), 0); // x2
    AddSpawn(currentTime += 1.0f, static_cast<int>(Enemytype::Soldier), 0);

    // 6
    AddSpawn(currentTime += 15.0f, static_cast<int>(Enemytype::Thrower), 0); // x1

    // 7
    AddSpawn(currentTime += 1.0f, static_cast<int>(Enemytype::Thrower), 0); // x1

    // 8
    AddSpawn(currentTime += 3.0f, static_cast<int>(Enemytype::Soldier), 0); // x1

    // 9
    AddSpawn(currentTime += 3.0f, static_cast<int>(Enemytype::Soldier), 0); // x1

    // 10
    AddSpawn(currentTime += 9.0f, static_cast<int>(Enemytype::Valorant), 0); // x1

    // 11
    AddSpawn(currentTime += 0.0f, static_cast<int>(Enemytype::Valorant), 0); // x1 (同時間)

    // 12
    AddSpawn(currentTime += 6.0f, static_cast<int>(Enemytype::Soldier), 0); // x1
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
    Emy->SetImageSize(0.5f,0.5f);
    Emy->SetVisible(false);
    Emy->SetLooping(false);
    return Emy;
}
void Spawner::AddSpawnEnemy(Enemytype type) {
    enemies.push_back(SpawnEnemy(type));
}

Spawner::~Spawner() {

}


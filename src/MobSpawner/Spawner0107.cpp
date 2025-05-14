#include "MobSpawner/MobSpawner.hpp"
void Spawner::CreateEnemies0107() {
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


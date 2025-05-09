#include "MobSpawner/MobSpawner.hpp"
void Spawner::CreateEnemiesRog53() {
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

}


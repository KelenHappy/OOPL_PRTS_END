#include "MobSpawner/MobSpawner.hpp"
void Spawner::CreateEnemiesCC5() {
    std::vector<int> Waittime={-1,-1,-1,-1,-1,-1} ;
    std::vector<std::vector<glm::vec2>> allPaths = {
        // 路線 1
        {
            {-347, -208},
            {-290, 100},
            {-208, 98},
            {-199, 225}
        },
        // 路線 2
        {
            {-152, -205},
            {-143, -121},
            {-140, -45},
            {-226, -42},
            {-200, 229}
        },
        // 路線 3
        {
            {113, 228},
            {117, 167},
            {145, -212},
            {443, -214}
        },
        // 路線 4 (右道)
        {
            {192, 227},
            {199, 166},
            {354, 168},
            {437, -207}
        },
        // 路線 5 (中路)
        {
            {-239, -118},
            {-226, -41},
            {-218, 32},
            {-301, 34},
            {-294, 104},
            {-129, 102},
            {-121, 169},
            {-201, 172},
            {-199, 229}
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
    AddSpawn(currentTime += 1.0f, Enemytype::BugA, 1); // x1
    AddSpawn(currentTime += 1.0f, Enemytype::BugA, 2); // x1
    AddSpawn(currentTime += 1.0f, Enemytype::BugA, 3); // x1
    AddSpawn(currentTime += 1.0f, Enemytype::BugA, 4); // x1

}


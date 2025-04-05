#include <vector>
#include "GameTimer.hpp"
#include "Enemy.hpp"
#include "Util/Transform.hpp"

class Spawner {
public:
    struct SpawnInfo {
        float spawnTime;  // 何時生成
        int enemyType;    // 生成的敵人類型
        int pathIndex;    // 怪物走哪條路線
    };

    struct Path {
        std::vector<Util::Transform> waypoints;
    };

    Spawner() : elapsedTime(0.0f) {}

    void AddPath(const std::vector<Util::Transform>& waypoints) {
        paths.push_back({waypoints});
    }

    void AddSpawn(float time, int type, int pathIndex) {
        spawnQueue.push_back({time, type, pathIndex});
    }

    void Update(float deltaTime) {
        elapsedTime += deltaTime;

        for (auto it = spawnQueue.begin(); it != spawnQueue.end();) {
            if (elapsedTime >= it->spawnTime) {
                SpawnEnemy(it->enemyType, paths[it->pathIndex]);
                it = spawnQueue.erase(it);
            } else {
                ++it;
            }
        }
    }

private:
    std::vector<SpawnInfo> spawnQueue;
    std::vector<Path> paths;
    float elapsedTime;

    void SpawnEnemy(int type, Path& path) {
        Enemy* enemy = new Enemy(type, path);
        enemies.push_back(enemy);
    }

    std::vector<Enemy*> enemies;
};
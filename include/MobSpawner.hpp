#include <vector>
#include "GameTimer.hpp"
#include "Enemy/Enemy.hpp"
#include "Enemy/EnemyType.hpp"
#include "Util/Transform.hpp"

class Spawner {
public:
    struct SpawnInfo {
        float spawnTime;  // 何時生成
        int enemyType;    // 生成的敵人類型
        int pathIndex;    // 怪物走哪條路線
    };
    Spawner();
    ~Spawner();
    std::shared_ptr<Enemy> SpawnEnemy(Enemytype type);
    struct Path {
        std::vector<Util::Transform> waypoints;
    };


    void AddPath(const std::vector<Util::Transform>& waypoints) {
        paths.push_back({waypoints});
    }

    void AddSpawn(float time, int type, int pathIndex) {
        spawnQueue.push_back({time, type, pathIndex});
    }



private:
    std::vector<SpawnInfo> spawnQueue;
    std::vector<Path> paths;
    void AddSpawnEnemy(Enemytype type);
    std::vector<std::shared_ptr<Enemy>> enemies;
};
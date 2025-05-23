#include <vector>

#include "Mapchoice.hpp"
#include "Pathpoints.hpp"
#include "Enemy/Enemy.hpp"
#include "Enemy/EnemyType.hpp"
#include "Util/Transform.hpp"

class Spawner {
public:
    struct SpawnInfo {
        float spawnTime;  // 何時生成
        Enemytype enemyType;    // 生成的敵人類型
        int pathIndex;    // 怪物走哪條路線
    };
    Spawner(Mapchoice Mc);
    ~Spawner();
    void Update();
    std::shared_ptr<Enemy> SpawnEnemy(Enemytype type);

    void AddPath(const std::shared_ptr<PathPoints> Point) {
        paths.push_back(Point);
    }

    void AddSpawn(float time, Enemytype type, int pathIndex);
    std::vector<std::shared_ptr<Enemy>> GetEnemies() {return enemies;}
    int GetAllEnemycount() {return spawnQueue.size();}
    std::vector<std::shared_ptr<Util::GameObject>> GetEnemiesGameobject() {
        std::vector<std::shared_ptr<Util::GameObject>>result;
        for (size_t i = 0; i < enemies.size(); i++) {
            result.emplace_back(enemies[i]);
            result.emplace_back(enemies[i]->GetHpBar());
        }
        return result;
    }
    void CreateSpawner(Mapchoice Mc);

private:
    int Time;
    int index;
    std::vector<SpawnInfo> spawnQueue;
    std::vector<std::shared_ptr<PathPoints>> paths;
    void AddSpawnEnemy(Enemytype type);
    std::vector<std::shared_ptr<Enemy>> enemies;
    void CreateEnemies0107();
    void CreateEnemiesCC5();
    void CreateEnemiesRog53();
};
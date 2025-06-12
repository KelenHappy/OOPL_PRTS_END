#include "MobSpawner/MobSpawner.hpp"
void Spawner::CreateEnemiesCC5() {
    std::vector<std::vector<int>> Waittime={{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,4,-1,-1,-1,-1,-1,-1,-1,-1},{-1,5,-1,-1,-1,-1,-1,-1,-1,-1}} ;
    std::vector<std::vector<glm::vec2>> allPaths = {
        // 路線 0
        {
            {-347, -208},
            {-290, 100},
            {-208, 98},
            {-199, 225}
        },
        // 路線 1
        {
            {-152, -205},
            {-143, -121},
            {-140, -45},
            {-226, -42},
            {-200, 229}
        },
        // 路線 2 (右中)
        {
            {113, 228},
            {117, 167},
            {145, -212},
            {443, -214}
        },
        // 路線 3 (右道)
        {
            {192, 227},
            {199, 166},
            {354, 168},
            {437, -207}
        },
        // 路線 4 (中路)
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
        path->setWaitTime(Waittime[0]);
        AddPath(path);
    }
    paths[1]->setWaitTime(Waittime[1]);
    std::shared_ptr<PathPoints> path = std::make_shared<PathPoints>();
    //路線五 右中 有延遲
    path->setPoint(allPaths[2]);
    path->setWaitTime(Waittime[2]);
    AddPath(path);
    float currentTime = 0.0f;
    paths[4]->setWaitTime(Waittime[2]);

     // 生怪資料 (時間點, 敵人數量, 間隔, 類型, 路線)
    auto spawn = [&](int count, float interval, Enemytype type, int pathIndex) {
        for (int i = 0; i < count; ++i)
            AddSpawn(currentTime + i * interval, type, pathIndex);
    };

    // 以下根據你的波次資料建立
    currentTime = 3;    spawn(1, 1, Enemytype::NoNameSoldier, 0);
    currentTime = 12;   spawn(2, 6, Enemytype::NoNameSoldier, 0);
    currentTime = 33;   spawn(2, 12, Enemytype::TraingMonster, 3);
    currentTime = 37;   spawn(2, 6, Enemytype::NoNameSoldier, 0);
    currentTime = 60;   spawn(3, 3, Enemytype::NoNameSoldier, 0);
    currentTime = 61;   spawn(4, 3, Enemytype::TraingMonster, 3);
    currentTime = 72;   spawn(1, 1, Enemytype::DefendSoloSoldier, 1);
    currentTime = 101;  spawn(3, 3.5, Enemytype::NoNameSoldier, 0);
    currentTime = 104;  spawn(1, 1, Enemytype::SoldierStudent, 2);
    currentTime = 108;  spawn(2, 9, Enemytype::TraingMonster, 3);
    currentTime = 110;  spawn(1, 1, Enemytype::ComplieMagic, 0);
    currentTime = 123;  spawn(3, 3, Enemytype::TraingMonster, 3);
    currentTime = 125;  spawn(3, 3, Enemytype::NoNameSoldier, 0);
    currentTime = 128;  spawn(1, 1, Enemytype::NoNameSoldier, 2);
    currentTime = 132;  spawn(1, 1, Enemytype::KingStudent, 5);
    currentTime = 135;  spawn(1, 1, Enemytype::DefendSoloSoldier, 1);
    currentTime = 147;  spawn(1, 1, Enemytype::ComplieMagic, 0);
    currentTime = 153;  spawn(3, 6, Enemytype::NoNameSoldier, 0);
    currentTime = 155;  spawn(3, 4, Enemytype::TraingMonster, 3);
    currentTime = 158;  spawn(2, 25, Enemytype::SoldierStudent, 2);
    currentTime = 168;  spawn(1, 1, Enemytype::DefendSoloSoldier, 1);
    currentTime = 177;  spawn(1, 1, Enemytype::KingStudent, 4);
    currentTime = 191;  spawn(4, 2.7, Enemytype::TraingMonster, 3);
    currentTime = 195;  spawn(2, 9, Enemytype::NoNameSoldier, 0);
    currentTime = 208;  spawn(1, 1, Enemytype::ComplieMagic, 0);
    currentTime = 211;  spawn(1, 1, Enemytype::SoldierStudent, 2);
    currentTime = 220;  spawn(2, 8, Enemytype::NoNameSoldier, 2);
    currentTime = 228;  spawn(1, 1, Enemytype::FailingSoldier, 4);
   // currentTime = 233  spawn(1, 1, Enemytype::DemonKnight2, 2);
    currentTime = 248;  spawn(2, 3, Enemytype::TraingMonster, 3);
    currentTime = 251;  spawn(1, 1, Enemytype::SoldierStudent, 2);
    currentTime = 256;  spawn(1, 1, Enemytype::KingStudent, 5);
   // currentTime = 278;  spawn(1, 1, Enemytype::DeSoldier, 2);
    currentTime = 278;  spawn(1, 1, Enemytype::DeSoldier, 2);
}



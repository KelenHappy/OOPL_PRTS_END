#include "MobSpawner/MobSpawner.hpp"
void Spawner::CreateEnemiesRog53() {
    std::vector<std::vector<int>> Waittime={{75,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,75,-1,-1,-1,-1,-1,-1,-1,-1},{-1,1,-1,-1,-1,-1,-1,-1,-1,-1}} ;
    std::vector<std::vector<glm::vec2>> allPaths = {
        {{-296,70}, {-311,-3}, {-134,-5}, {-147,-178}, {441,-167}},         // 路线1
        {{40,-2}, {39,137}, {197,139}, {210,70}, {374,71}, {444,-162}},     // 路线2
        {{191,198}, {204,69}, {378,72}, {433,-171}},                         // 路线3
        {{-241,-173}, {437,-168}},                                           // 路线4
        {{-274,205},{-283.0f, 138.0f}, {-293,68}, {-126,69}, {-126,138}, {199,142}, {210,68}, {378,72}, {433,-169}}, // 路线5
        {{-440,-175}, {438,-165}},                                           // 路线6
        {{348,200}, {270, 197},{195,201}, {207,68}, {375,72}, {433,-171}},              // 路线7
        {{-275,203}, {-296,71}, {-309,-5}, {-134,-5}, {-148,-176}, {437,-173}}, // 路线8
        {{44,-80}, {41,3}, {35,140}, {199,140}, {206,72}, {374,73}, {448,-169}}, // 路线9
        {{349,205}, {193,205}, {207,71}, {374,73}, {442,-163}},              // 路线10
        {{-438.0f, -173.0f}, {-244.0f, -173.0f}, {443.0f, -167.0f}},        // 路线11
        {{40.0f, -78.0f}, {43.0f, -174.0f}, {437.0f, -169.0f}}// 路线12
        };
    allPaths.push_back({{42.0f, -83.0f}, {38.0f, 140.0f}, {203.0f, 140.0f}, {208.0f, 68.0f}, {375.0f, 72.0f}, {443.0f, -170.0f}});
    for(int i=0;i<4;i++) {
        std::shared_ptr<PathPoints> path = std::make_shared<PathPoints>();
        path->setPoint(allPaths[i]);
        path->setWaitTime(Waittime[0]);
        AddPath(path);
    }//R0~3
    for(int i=4;i<7;i++) {
        std::shared_ptr<PathPoints> path = std::make_shared<PathPoints>();
        path->setPoint(allPaths[i]);
        path->setWaitTime(Waittime[1]);
        AddPath(path);
    }
    //R4,5,6
    std::shared_ptr<PathPoints> path = std::make_shared<PathPoints>();
    path->setPoint(allPaths[4]);
    path->setWaitTime(Waittime[2]);
    AddPath(path);
    //R7
    for(int i=7;i<11;i++) {
        std::shared_ptr<PathPoints> path = std::make_shared<PathPoints>();
        path->setPoint(allPaths[i]);
        path->setWaitTime(Waittime[3]);
        AddPath(path);
    }//R8~11
    path = std::make_shared<PathPoints>();
    path->setPoint(allPaths[6]);
    path->setWaitTime(Waittime[2]);
    AddPath(path);
    //R12
    path = std::make_shared<PathPoints>();
    path->setPoint(allPaths[11]);
    path->setWaitTime(Waittime[4]);
    AddPath(path);
    //R13
    path = std::make_shared<PathPoints>();
    path->setPoint(allPaths[12]);
    path->setWaitTime(Waittime[2]);
    AddPath(path);
    //R14
    float currentTime = 0.0f;


     // 生怪資料 (時間點, 敵人數量, 間隔, 類型, 路線)
    auto spawn = [&](int count, float interval, Enemytype type, int pathIndex) {
        for (int i = 0; i < count; ++i)
            AddSpawn(currentTime + i * interval, type, pathIndex);
    };

    // 以下根據你的波次資料建立
    currentTime = 0;
    AddSpawn(0,  Enemytype::CrazyHostThrower, 0);
    AddSpawn(0,  Enemytype::CrazyHostThrower, 1);
    AddSpawn(0,  Enemytype::CrazyHostThrower, 2);
    AddSpawn(0,  Enemytype::CrazyHostThrower, 3);

    currentTime = 5;
    spawn(12, 18, Enemytype::SnowmanTeam, 4);

    currentTime = 16;
    spawn(11, 18, Enemytype::SnowmanTeam, 5);

    currentTime = 55;
    spawn(2, 1, Enemytype::ColdWolf, 6);

    currentTime = 55;
    spawn(2, 70, Enemytype::CrazyHostLeader, 7);

    currentTime = 75;
    spawn(2, 1, Enemytype::ColdWolf, 5);

    currentTime = 80;
    AddSpawn(80,  Enemytype::CrazyHostThrower, 8);
    AddSpawn(80,  Enemytype::CrazyHostThrower, 9);
    AddSpawn(80,  Enemytype::CrazyHostThrower, 10);
    AddSpawn(80,  Enemytype::CrazyHostThrower, 11);

    currentTime = 85;
    spawn(2, 35, Enemytype::CrazyHostLeader, 12);
    spawn(2, 35, Enemytype::CrazyHostLeader, 14);

    currentTime = 105;
    spawn(6, 20, Enemytype::ColdBug, 13);

    currentTime = 135;
    spawn(2, 1, Enemytype::ColdWolf, 6);

    currentTime = 160;
    spawn(2, 1, Enemytype::ColdWolf, 4);

    currentTime = 185;
    spawn(1, 1, Enemytype::CrazyHostLeader, 7);
}

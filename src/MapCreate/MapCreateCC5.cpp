#include "Map.hpp"
struct vec2 {
    float x, y;
    vec2(float _x, float _y) : x(_x), y(_y) {}
};

void Map::CreateCC5() {
    TowerHP=3;
    EnemyTotalMax=10;
    EnemyTotal=0;
    PutLimit=5;
    cost=10;
    mapsize={10,7};
    m_map = std::make_shared<CreateIMG>("/Maps/cc5.png", -10);
    m_block.clear();
    #include <vector>
#include <glm/glm.hpp> // or your vec2 implementation

using vec2 = glm::vec2; // or your vec2 type

std::vector<vec2> positions = {
    vec2(-458.000000, -196.000000), vec2(-351.000000, -200.000000), vec2(-250.000000, -198.000000),
    vec2(-155.000000, -196.000000), vec2(-57.000000, -193.000000), vec2(46.000000, -194.000000),
    vec2(144.000000, -211.000000), vec2(240.000000, -211.000000), vec2(338.000000, -212.000000),
    vec2(443.000000, -211.000000), vec2(-430.000000, -116.000000), vec2(-329.000000, -119.000000),
    vec2(-238.000000, -115.000000), vec2(-148.000000, -120.000000), vec2(-50.000000, -112.000000),
    vec2(47.000000, -115.000000), vec2(140.000000, -122.000000), vec2(238.000000, -110.000000),
    vec2(323.000000, -124.000000), vec2(417.000000, -123.000000), vec2(-400.000000, -40.000000),
    vec2(-315.000000, -48.000000), vec2(-226.000000, -47.000000), vec2(-140.000000, -45.000000),
    vec2(-49.000000, -32.000000), vec2(42.000000, -40.000000), vec2(130.000000, -42.000000),
    vec2(225.000000, -28.000000), vec2(313.000000, -37.000000), vec2(399.000000, -41.000000),
    vec2(-400.000000, 40.000000), vec2(-301.000000, 31.000000), vec2(-220.000000, 35.000000),
    vec2(-132.000000, 45.000000), vec2(-46.000000, 48.000000), vec2(42.000000, 45.000000),
    vec2(125.000000, 29.000000), vec2(222.000000, 46.000000), vec2(305.000000, 48.000000),
    vec2(383.000000, 34.000000), vec2(-384.000000, 118.000000), vec2(-292.000000, 100.000000),
    vec2(-213.000000, 97.000000), vec2(-126.000000, 105.000000), vec2(-45.000000, 115.000000),
    vec2(41.000000, 114.000000), vec2(119.000000, 99.000000), vec2(209.000000, 114.000000),
    vec2(294.000000, 114.000000), vec2(371.000000, 104.000000), vec2(-369.000000, 186.000000),
    vec2(-289.000000, 184.000000), vec2(-202.000000, 167.000000), vec2(-125.000000, 168.000000),
    vec2(-45.000000, 178.000000), vec2(34.000000, 177.000000), vec2(115.000000, 170.000000),
    vec2(196.000000, 169.000000), vec2(275.000000, 171.000000), vec2(352.000000, 166.000000),
    vec2(-363.000000, 244.000000), vec2(-290.000000, 245.000000), vec2(-199.000000, 226.000000),
    vec2(-122.000000, 241.000000), vec2(-40.000000, 243.000000), vec2(35.000000, 242.000000),
    vec2(111.000000, 219.000000), vec2(188.000000, 217.000000), vec2(275.000000, 239.000000),
    vec2(352.000000, 239.000000)
};
    std::vector<std::string> blockPattern = {
        "hghghhgggg",
        "hggghhghgg",
        "hggghgghhg",
        "hgghhhghhg",
        "hggghhghhg",
        "hhgghhgggg",
        "nngnnnggnn"
    };
    std::vector<std::string> canplace = {
        "nnnnyynyyn",
        "nnnnnnnyyy",
        "nynyyyyynn",
        "nyynynyyyn",
        "yyyyynnnyn",
        "yyyyynnnyy",
        "nnnnnnnnnn"
    };
    bool  yn;
    for (size_t i = 0; i < mapsize.x*mapsize.y; i++) {
        int row = i / int(mapsize.x);
        int col = i % int(mapsize.x);
        BlockState state;

        switch (blockPattern[row][col]) {
            case 'h': state = BlockState::HIGH; break;
            case 'g': state = BlockState::GROUND; break;
            case 'b': state = BlockState::BOTH; break;
            case 'n': state = BlockState::NONE; break;
            default: state = BlockState::NONE; break;
        }
        switch (canplace[row][col]) {
            case 'y': yn=false; break;
            case 'n': yn=true; break;
            default: yn=false; break;
        }

        std::shared_ptr<Block> bk = std::make_shared<Block>(col, row, state,0.8);
        bk->m_Transform.translation.x = positions[i].x;
        bk->m_Transform.translation.y = positions[i].y;
        bk->SetVisible(true);
        bk->HaveCharacter=yn;
        this->m_block.push_back(bk);
    }
}

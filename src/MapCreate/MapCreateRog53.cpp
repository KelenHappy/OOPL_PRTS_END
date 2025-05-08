#include "Map.hpp"
struct vec2 {
    float x, y;
    vec2(float _x, float _y) : x(_x), y(_y) {}
};
void Map::CreateRog53() {
    TowerHP=3;
    EnemyTotalMax=10;
    EnemyTotal=0;
    PutLimit=7;
    cost=10;
    mapsize={10,6};
    m_map = std::make_shared<CreateIMG>("/Maps/rog53.png", -10);
    m_block.clear();
    std::vector<vec2> positions = {
        vec2(-442.000000, -169.000000), vec2(-340.000000, -170.000000), vec2(-246.000000, -172.000000),
        vec2(-148.000000, -173.000000), vec2(-49.000000, -173.000000), vec2(42.000000, -174.000000),
        vec2(139.000000, -170.000000), vec2(242.000000, -169.000000), vec2(338.000000, -169.000000),
        vec2(432.000000, -171.000000), vec2(-438.000000, -77.000000), vec2(-338.000000, -77.000000),
        vec2(-239.000000, -79.000000), vec2(-143.000000, -85.000000), vec2(-51.000000, -74.000000),
        vec2(46.000000, -79.000000), vec2(134.000000, -76.000000), vec2(231.000000, -82.000000),
        vec2(325.000000, -77.000000), vec2(411.000000, -85.000000), vec2(-393.000000, 2.000000),
        vec2(-310.000000, -3.000000), vec2(-221.000000, -1.000000), vec2(-131.000000, -2.000000),
        vec2(-49.000000, 10.000000), vec2(41.000000, 3.000000), vec2(132.000000, 6.000000),
        vec2(218.000000, -2.000000), vec2(309.000000, 7.000000), vec2(382.000000, -3.000000),
        vec2(-384.000000, 73.000000), vec2(-298.000000, 74.000000), vec2(-212.000000, 74.000000),
        vec2(-121.000000, 73.000000), vec2(-47.000000, 80.000000), vec2(35.000000, 80.000000),
        vec2(123.000000, 81.000000), vec2(208.000000, 69.000000), vec2(295.000000, 68.000000),
        vec2(381.000000, 70.000000), vec2(-373.000000, 152.000000), vec2(-292.000000, 140.000000),
        vec2(-206.000000, 141.000000), vec2(-121.000000, 141.000000), vec2(-46.000000, 142.000000),
        vec2(37.000000, 137.000000), vec2(123.000000, 135.000000), vec2(202.000000, 134.000000),
        vec2(288.000000, 148.000000), vec2(369.000000, 152.000000), vec2(-373.000000, 215.000000),
        vec2(-274.000000, 213.000000), vec2(-196.000000, 214.000000), vec2(-117.000000, 215.000000),
        vec2(-42.000000, 216.000000), vec2(37.000000, 216.000000), vec2(117.000000, 206.000000),
        vec2(198.000000, 202.000000), vec2(275.000000, 203.000000), vec2(355.000000, 207.000000)
    };
    std::vector<std::string> blockPattern = {
        "gggggggggg",
        "hhhghghghg",
        "gggghghghg",
        "gggghghggg",
        "hghggggghh",
        "hghhhhgggg"
    };
    std::vector<std::string> canplace = {
        "nnnyyyyyyn",
        "nnyynnnyny",
        "yyyynnnyyy",
        "ynyyynyyyy",
        "ynnyyyyyyn",
        "nnnnyyynnn"
    };
    for (size_t i = 0; i < mapsize.x*mapsize.y; i++) {
        int row = i / int(mapsize.x);
        int col = i % int(mapsize.x);
        BlockState state;
        bool  yn;

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
        bk->SetVisible(false);
        bk->HaveCharacter=yn;
        this->m_block.push_back(bk);
    }
}

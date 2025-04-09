#include "Map.hpp"
#include "Util/Logger.hpp"
struct vec2 {
    float x, y;
    vec2(float _x, float _y) : x(_x), y(_y) {}
};
Map::Map() {
    TowerHP=3;
    EnemyTotalMax=10;
    EnemyTotal=0;
    PutLimit=5;
    cost=10;
    m_map = std::make_shared<CreateIMG>("/Maps/main_0107/main_0107.png", -10);
    std::vector<vec2> positions = {
        vec2(-502.000000, -155.000000), vec2(-374.000000, -162.000000), vec2(-251.000000, -159.000000),
        vec2(-114.000000, -164.000000), vec2(-4.000000, -167.000000), vec2(119.000000, -170.000000),
        vec2(238.000000, -170.000000), vec2(355.000000, -168.000000), vec2(484.000000, -169.000000),
        vec2(-471.000000, -55.000000), vec2(-347.000000, -62.000000), vec2(-231.000000, -64.000000),
        vec2(-115.000000, -67.000000), vec2(-1.000000, -57.000000), vec2(111.000000, -56.000000),
        vec2(229.000000, -57.000000), vec2(345.000000, -55.000000), vec2(470.000000, -53.000000),
        vec2(-440.000000, 36.000000), vec2(-328.000000, 30.000000), vec2(-214.000000, 35.000000),
        vec2(-107.000000, 29.000000), vec2(1.000000, 39.000000), vec2(108.000000, 37.000000),
        vec2(213.000000, 37.000000), vec2(320.000000, 35.000000), vec2(444.000000, 44.000000),
        vec2(-430.000000, 136.000000), vec2(-302.000000, 121.000000), vec2(-199.000000, 114.000000),
        vec2(-102.000000, 117.000000), vec2(3.000000, 135.000000), vec2(107.000000, 138.000000),
        vec2(208.000000, 138.000000), vec2(317.000000, 134.000000), vec2(424.000000, 137.000000),
        vec2(-401.000000, 214.000000), vec2(-300.000000, 217.000000), vec2(-194.000000, 215.000000),
        vec2(-95.000000, 198.000000), vec2(3.000000, 200.000000), vec2(102.000000, 202.000000),
        vec2(203.000000, 203.000000), vec2(303.000000, 204.000000), vec2(403.000000, 205.000000)
    };

    std::vector<std::string> blockPattern = {
        "hhhgggggn",
        "hggghhhhn",
        "ggngggggn",
        "hggghhhhn",
        "hhhgggggn"
    };

    for (size_t i = 0; i < positions.size(); i++) {
        int row = i / 9;
        int col = i % 9;
        BlockState state;

        switch (blockPattern[row][col]) {
            case 'h': state = BlockState::HIGH; break;
            case 'g': state = BlockState::GROUND; break;
            case 'b': state = BlockState::BOTH; break;
            case 'n': state = BlockState::NONE; break;
            default: state = BlockState::NONE; break;
        }

        std::shared_ptr<Block> bk = std::make_shared<Block>(col, row, state);
        bk->m_Transform.translation.x = positions[i].x;
        bk->m_Transform.translation.y = positions[i].y;
        bk->SetVisible(false);
        this->m_block.push_back(bk);
    }
    CreatotherItem();

}
void Map::Update() {
    m_PutLimit->SetText("可放置角色:"+std::to_string(PutLimit));
    m_EnemyText->SetText(std::to_string(EnemyTotal)+"/"+std::to_string(EnemyTotalMax));
    m_HPText->SetText(std::to_string(TowerHP));
    m_Cost->SetText(std::to_string(cost));
}
void Map::CreatotherItem() {
    m_Cost=std::make_shared<TextBox>(40);
    m_Cost->SetText(std::to_string(cost));
    m_Cost->SetZIndex(27);
    m_Cost->m_Transform.translation={ 620, -173 };
    m_CostBar=std::make_shared<ImgItem>("/Maps/CostBar.png");
    m_CostBar->m_Transform.scale={ 0.2, 0.2 };
    m_CostBar->m_Transform.translation={ 582, -168 };
    m_CostBar->SetZIndex(26);
    m_EmemyandHp=std::make_shared<ImgItem>("/Maps/EnemyandHP.png");
    m_EmemyandHp->m_Transform.scale={ 0.8, 0.8 };
    m_EmemyandHp->m_Transform.translation={ 0, 340 };
    m_EmemyandHp->SetZIndex(60);
    m_PutLimit=std::make_shared<TextBox>(20);
    m_PutLimit->SetText("可放置角色:"+std::to_string(PutLimit));
    m_PutLimit->SetZIndex(27);
    m_PutLimit->m_Transform.translation={565,-212};
    m_PutlimitBar=std::make_shared<ImgItem>("/Maps/CardBack.png");
    m_PutlimitBar->m_Transform.translation={570,-212};
    m_PutlimitBar->m_Transform.scale={ 0.65, 0.1 };
    m_PutlimitBar->SetZIndex(26);
    m_HPText=std::make_shared<TextBox>(30);
    m_HPText->SetText(std::to_string(TowerHP));
    m_HPText->SetZIndex(61);
    m_HPText->SetColor(Util::Colors::DEEP_PINK);
    m_HPText->m_Transform.translation={153,337};
    m_EnemyText=std::make_shared<TextBox>(30);
    m_EnemyText->SetText(std::to_string(EnemyTotal)+"/"+std::to_string(EnemyTotalMax));
    m_EnemyText->m_Transform.translation={-72,337};
    m_EnemyText->SetZIndex(61);
}
std::vector<std::shared_ptr<Util::GameObject>> Map::GetChildren() const {
    std::vector<std::shared_ptr<Util::GameObject>> result;
    for(size_t i=0;i<m_block.size();i++) {
        result.push_back(m_block[i]);
    }
    result.push_back(m_Cost);
    result.push_back(m_EmemyandHp);
    result.push_back(m_CostBar);
    result.push_back(m_PutLimit);
    result.push_back(m_PutlimitBar);
    result.push_back(m_HPText);
    result.push_back(m_EnemyText);
    result.push_back(m_map);
    return result;
}
bool Map::Takemapcost(int n) {
    if (cost>=n) {
        cost-=n;
        return true;
    }
    return false;
}
std::vector<std::shared_ptr<Block>> Map::GetHaveCharacterBlock(BlockState B) {
    std::vector<std::shared_ptr<Block>> result;
    for(size_t i=0;i<m_block.size();i++) {
        if (m_block[i]->GetBlockState()==B) {
            result.push_back(m_block[i]);
        }
    }
    return result;
}
std::vector<std::shared_ptr<Block> > Map::GetTypeOfBlock(BlockState B) {
    std::vector<std::shared_ptr<Block>> result;
    for(size_t i=0;i<m_block.size();i++) {
        if (m_block[i]->GetBlockState()==B&&m_block[i]->HaveCharacter) {
            result.push_back(m_block[i]);
        }
    }
    return result;
}






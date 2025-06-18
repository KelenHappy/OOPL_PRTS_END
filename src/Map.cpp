#include "Map.hpp"
#include "Util/Logger.hpp"
struct vec2 {
    float x, y;
    vec2(float _x, float _y) : x(_x), y(_y) {}
};
Map::Map(Mapchoice Mc) {
    TowerHP=3;
    EnemyTotalMax=10;
    EnemyTotal=0;
    PutLimit=5;
    cost=10;
    CreateMapchoice(Mc);
    CreatotherItem();
    isEnd=false;

}
void Map::Update() {
    //m_PutLimit->SetText("可放置角色:"+std::to_string(PutLimit));
    m_PutLimit->SetText(" ");
    m_PutlimitBar->SetVisible(false);
    m_EnemyText->SetText(std::to_string(EnemyTotal)+"/"+std::to_string(EnemyTotalMax));
    m_HPText->SetText(std::to_string(TowerHP));
    m_Cost->SetText(std::to_string(cost));
}
void Map::CreatotherItem() {
    m_Cost=std::make_shared<TextBox>(40);
    m_Cost->SetText(std::to_string(cost));
    m_Cost->SetZIndex(27);
    m_Cost->m_Transform.translation={ 620, -205 };
    m_CostBar=std::make_shared<ImgItem>("/Maps/CostBar.png");
    m_CostBar->m_Transform.scale={ 0.2, 0.2 };
    m_CostBar->m_Transform.translation={ 582, -200  };
    m_CostBar->SetZIndex(26);
    m_EmemyandHp=std::make_shared<ImgItem>("/Maps/EnemyandHP.png");
    m_EmemyandHp->m_Transform.scale={ 0.8, 0.8 };
    m_EmemyandHp->m_Transform.translation={ 0, 340 };
    m_EmemyandHp->SetZIndex(60);
    m_PutLimit=std::make_shared<TextBox>(20);
    m_PutLimit->SetText("可放置角色:"+std::to_string(PutLimit));
    m_PutLimit->SetZIndex(27);
    m_PutLimit->m_Transform.translation={565,-245};
    m_PutlimitBar=std::make_shared<ImgItem>("/Maps/CardBack.png");
    m_PutlimitBar->m_Transform.translation={570,-245};
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
    m_endmove=std::make_shared<ImgItem>("/Maps/endmove.png");
    m_endmove->SetZIndex(100);
    m_endmove->SetVisible(false);
    m_endmove->m_Transform.translation={-800,0};
    m_endB=std::make_shared<ImgItem>("/Maps/endb.png");
    m_endB->SetZIndex(99);
    m_endB->SetVisible(false);
    m_endB->m_Transform.translation={0,0};
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
    result.push_back(m_endB);
    result.push_back(m_endmove);
    return result;
}
bool Map::Takemapcost(int n) {
    if (cost>=n) {
        cost-=n;
        return true;
    }
    return false;
}
std::vector<std::shared_ptr<Block>> Map::GetHaveCharacterBlock(BlockState B, bool HaveCharacter) {
    std::vector<std::shared_ptr<Block>> result;
    for(size_t i=0;i<m_block.size();i++) {
        if (m_block[i]->GetBlockState()==B&&m_block[i]->HaveCharacter==HaveCharacter) {
            result.push_back(m_block[i]);
        }
    }
    return result;
}
std::vector<std::shared_ptr<Block> > Map::GetTypeOfBlock(BlockState B) {
    std::vector<std::shared_ptr<Block>> result;
    for(size_t i=0;i<m_block.size();i++) {
        if (m_block[i]->GetBlockState()==B) {
            result.push_back(m_block[i]);
        }
    }
    return result;
}

void Map::openMapblock(BlockState B) {
    for(size_t i=0;i<m_block.size();i++) {
        if (m_block[i]->GetBlockState()==B&&m_block[i]->HaveCharacter==false) {
            m_block[i]->SetVisible(true);
            m_block[i]->ChangeImage("/Maps/block.png") ;
        }
        else
            m_block[i]->SetVisible(false);
    }
}
void Map::closeMapblock() {
    for(size_t i=0;i<m_block.size();i++) {
       m_block[i]->SetVisible(false);
    }
}

//放入幹員的範圍getblock
std::vector<std::shared_ptr<Block>> Map::ExtractBlocksFromPattern(
    const std::vector<std::vector<std::string>>& range,
    int base_x, int base_y, Direction dir)
{
    std::vector<std::shared_ptr<Block>> result;

    int center_i = -1, center_j = -1;
    int rows = range.size();
    int cols = range[0].size();

    // 找中心 "2"
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (range[i][j] == "2") {
                center_i = i;
                center_j = j;
                break;
            }

    if (center_i == -1) {
        std::cerr << "中心 '2' 未找到" << std::endl;
        return result;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            const std::string& val = range[i][j];
            if (val == "1" || val == "2") {
                int di = i - center_i;
                int dj = j - center_j;
                int dx, dy;

                // 旋轉
                switch (dir) {
                    case Direction::EAST:  dx = dj;  dy = di;  break;
                    case Direction::SOUTH: dx = -di; dy = dj;  break;
                    case Direction::WEST:  dx = -dj; dy = -di; break;
                    case Direction::NORTH: dx = di;  dy = -dj; break;
                    default:
                        std::cout << "Error Direction Map.cpp 151" << std::endl;
                        dx = dj;
                        dy = di;
                        break;
                }
                int x = base_x + dx;
                int y = base_y + dy;
                // 檢查是否落在合法地圖內
                if (x >= 0 && x < mapsize.x && y >= 0 && y < mapsize.y) {
                    result.push_back(m_block[x+mapsize.x*y]);
                }
            }
        }
    }

    return result;
}
void Map::CreateMapchoice(Mapchoice Mc) {
    switch (Mc) {
        case(Mapchoice::cc5):
            CreateCC5();
        break;
        case(Mapchoice::main17):
            CreateMain0107();
        break;
        case(Mapchoice::rog53):
            CreateRog53();
        break;
    }
}



void Map::End() {
    if (!isEnd){
        m_stage = 0;
        delay=0;
        isEnd=true;

        m_endB->m_Transform.translation={0, 0}; // 背景置中（若需）
        m_endmove->m_Transform.translation={-1280, 0}; // 從畫面左邊外面開始
        m_endmove->SetVisible(true);
        m_endB->SetVisible(true);
    }
}
bool Map::EndAnimeUpdate() {
    if (isEnd){
        float m_speed = 30.0f; // 移動速度（像素/秒）
        float m_stopTime = 1000.0f; // 停留時間（毫秒）
        if (m_stage == 0) {
            // 移動進場
            float x = m_endmove->m_Transform.translation.x;
            if (x < 0) {
                x += m_speed ;
                if (x >= 0) {
                    x = 0;
                    m_stage = 1;
                }
                m_endmove->m_Transform.translation.x=x;
            }
        }
        else if (m_stage == 1) {
            // 停留
            delay+=m_speed;
            if (delay>=m_stopTime) {
                m_stage = 2;
            }
        }
        else if (m_stage == 2) {
            // 離場
            float x = m_endmove->m_Transform.translation.x;
            if (x < 1280) {
                x += m_speed;
                m_endmove->m_Transform.translation.x=x;
            } else {
                m_stage = 3;
            }
        }
        else if (m_stage == 3) {
            return true;
        }
    }
    return false;
}

void Map::UpdateCard() {
    for(size_t i=0;i<m_Card.size();i++) {
        m_Card[i]->UpdateCardS();
    }
}
void Map::UpdateCardLine() {
    UpdateCard();
    int n=0;
    for(size_t i=0;i<m_Card.size();i++) {
        m_Card[i]->UpdateCard();
        if(m_Card[i]->GetCharacter()->GetVisibility()==false) {
            m_Card[i]->SetTranform(588-int(n*(144)/0.8*0.6),-318);
            n++;
        }
        else {
            m_Card[i]->SetTranform(588-int(15*(144)/0.8*0.6),-318);
        }
    }
}




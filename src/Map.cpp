//
// Created by AaronChiu on 2025/3/14.
//

#include "Map.hpp"
Map::Map() {
    m_map=std::make_shared<CreateIMG>("/Maps/main_0107/main_0107.png",-10);
    for (int i=0;i<5;i++) {
        for (int j=0;j<9;j++) {
            std::shared_ptr<Block> bk=std::make_shared<Block>(j,i,BlockState::NONE);
            bk->m_Transform.
            this->m_block.push_back(bk);
        }
    }
}

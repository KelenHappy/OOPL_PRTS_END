//
// Created by AaronChiu on 2025/3/14.
//

#ifndef MAP_H
#define MAP_H
#include "CreateIMG.h"
#include "Util/GameObject.hpp"
class Map :public Util::GameObject{
    public:
    Map() {
        m_map=std::make_shared<CreateIMG>("/Maps/main_0107/main_0107.png",-10);

    }
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        return {m_map};
    }
    private:
    std::vector<std::shared_ptr<Util::GameObject>> m_block;
    std::shared_ptr<CreateIMG> m_map;
};
#endif //MAP_H

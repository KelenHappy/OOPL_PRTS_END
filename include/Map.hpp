//
// Created by AaronChiu on 2025/3/14.
//

#ifndef MAP_HPP
#define MAP_HPP
#include "block.h"
#include "CreateIMG.hpp"
#include "Util/GameObject.hpp"
class Map :public Util::GameObject{
    public:
    Map() ;
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        std::vector<std::shared_ptr<Util::GameObject>> result;
        std::transform(m_block.begin(), m_block.end(), std::back_inserter(result),
            [](const std::shared_ptr<Block>& block) {
                return std::static_pointer_cast<Util::GameObject>(block);
            });
        result.push_back(m_map);
        return result;
    }

    private:
    std::vector<std::shared_ptr<Block>>m_block;
    std::shared_ptr<CreateIMG> m_map;
};
#endif //MAP_HPP

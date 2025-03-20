//
// Created by AaronChiu on 2025/3/14.
//

#ifndef MAP_HPP
#define MAP_HPP
#include "Block.hpp"
#include "CreateIMG.hpp"
#include "Util/GameObject.hpp"
class Map :public Util::GameObject{
    public:
    Map() ;
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        std::vector<std::shared_ptr<Util::GameObject>> result;
        for(int i=0;i<m_block.size();i++) {
            result.push_back(m_block[i]);
        }
        result.push_back(m_map);
        return result;
    }
    [[nodiscard]] std::vector<std::shared_ptr<Block>> Getblock() {return m_block;}

    private:
    std::vector<std::shared_ptr<Block>>m_block;
    std::shared_ptr<CreateIMG> m_map;
};
#endif //MAP_HPP

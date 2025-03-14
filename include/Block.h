//
// Created by AaronChiu on 2025/3/14.
//

#ifndef BLOCK_H
#define BLOCK_H
#include "BlockState.hpp"
#include "Util/GameObject.hpp"

class Block:public Util::GameObject {
    public:
    Block(int x,int y,BlockState BS);
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    BlockState GetBlockState(){return blockState;}
    void SetBlockState(BlockState b){blockState=b;}


    private:
    int x;
    int y;
    BlockState blockState=BlockState::NONE;



};
#endif //BLOCK_H

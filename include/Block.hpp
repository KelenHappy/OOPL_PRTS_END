//
// Created by AaronChiu on 2025/3/14.
//

#ifndef BLOCK_H
#define BLOCK_H
#include "BlockState.hpp"
#include "CreateIMG.hpp"
#include "Util/GameObject.hpp"

class Block:public Util::GameObject {
    public:
    bool carry;
    Block(int x,int y,BlockState BS);
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    BlockState GetBlockState(){return blockState;}
    void SetBlockState(BlockState b){blockState=b;}
    int GetX(){ return x; }
	int GetY(){ return y; }

    private:
    bool HaveCharacter;
    int x;
    int y;
    BlockState blockState=BlockState::NONE;



};
#endif //BLOCK_H

#include "Block.h"

Block::Block(int x,int y,BlockState BS) {
    m_Transform.scale={1.02f, 0.95f};//調整大小 100*100->102*95
    this->x=x;
    this->y=y;
    this->blockState=BS;
}

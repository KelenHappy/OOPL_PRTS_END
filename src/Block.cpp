#include "Block.hpp"
#include "Util/Image.hpp"
//透明度45%
Block::Block(int x,int y,BlockState BS) {
    if(x==0)m_Drawable = std::make_shared<Util::Image>(RESOURCE_DIR"/Maps/block1.png");
    else m_Drawable = std::make_shared<Util::Image>(RESOURCE_DIR"/Maps/block.png");
    m_Transform.scale={1.02f, 0.95f};//調整大小 100*100->102*95
    this->x=x;
    this->y=y;
    this->HaveCharacter = false;
    this->blockState=BS;
}

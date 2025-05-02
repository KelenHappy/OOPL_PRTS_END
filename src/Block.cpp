#include "Block.hpp"
#include "Util/Image.hpp"
//透明度45%
Block::Block(int x,int y,BlockState BS) {
    m_Drawable = std::make_shared<Util::Image>(RESOURCE_DIR"/Maps/block.png");
    m_Transform.scale={1.02f, 0.95f};//調整大小 100*100->102*95
    this->x=x;
    this->y=y;
    this->HaveCharacter = false;
    //this->Character = nullptr;
    this->blockState=BS;
    this->Characterindex=-1;
}
void Block::ChangeImage( std::string newImagePath) {
    auto imagePtr = std::static_pointer_cast<Util::Image>(m_Drawable);
    if (imagePtr) {
        imagePtr->SetImage(RESOURCE_DIR+newImagePath);
    }
}
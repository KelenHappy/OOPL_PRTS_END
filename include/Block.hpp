
#ifndef BLOCK_H
#define BLOCK_H
#include "BlockState.hpp"
#include "CreateIMG.hpp"
#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"

class Block:public Util::GameObject {
    public:
    bool carry;
    bool HaveCharacter;
    Block(int x,int y,BlockState BS);
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    glm::vec2 GetPosition(){return m_Transform.translation;}
    BlockState GetBlockState(){return blockState;}
    void SetBlockState(BlockState b){blockState=b;}
    int GetX(){ return x; }
	int GetY(){ return y; }
    void placeCharacter(int CI) {
        Characterindex=CI;
        HaveCharacter=true;
    }
    void outplaceCharacter() {
        Characterindex=-1;
        HaveCharacter=false;
    }
    private:
    int x;
    int y;
    int Characterindex;
    BlockState blockState=BlockState::NONE;
    //std::shared_ptr<AnimatedCharacter> Character;

};
#endif //BLOCK_H

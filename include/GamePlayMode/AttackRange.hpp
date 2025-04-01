#ifndef ATTACK_RANGE_HPP
#define ATTACK_RANGE_HPP
#include "Block.hpp"
#include <iostream>
class AttackRange{
public:
	void SetRange(std::shared_ptr<std::vector<Block>> Range){
		if (Range) {  // 避免空指针
            AttackRangeNow = std::make_shared<std::vector<Block>>(*Range); // 	複製vector 數據
        }		
	}

protected:
	std::shared_ptr<std::vector <Block>> AttackRangeNow = nullptr;
	std::shared_ptr<std::vector <Block> >AttackRangeDefault = nullptr;
};
#endif

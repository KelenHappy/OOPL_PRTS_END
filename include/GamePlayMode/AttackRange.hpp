#ifndef ATTACK_RANGE_HPP
#define ATTACK_RANGE_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "Block.hpp"

class AttackRange {
public:
	void SetAttackRangeNum(int Range){
		AttackRangeNum = Range;
	}
	int GetAttackRangeNum(){
		return AttackRangeNum;
	}
    void SetAttackRangeNow(std::vector<std::shared_ptr<Block>> Range) {
		AttackRangeNow = Range; // 複製 vector 數據

    }

    void SetAttackRangeDefault(std::vector<std::shared_ptr<Block>> Range) {
		AttackRangeDefault = Range;
		AttackRangeNow=AttackRangeDefault;

    }


    void DefaultRange(std::vector<std::vector<std::string>> In) {
        m_DefaultRange = In;
    }
	std::vector<std::vector<std::string>> GetDefaultRange() {return m_DefaultRange;}
	std::vector<std::shared_ptr<Block>> GetAttackRangeNow(){return  AttackRangeNow;}
protected:
	int AttackRangeNum = 0 ;
    std::vector<std::vector<std::string>> m_DefaultRange;
    std::vector<std::shared_ptr<Block>> AttackRangeNow;
    std::vector<std::shared_ptr<Block>> AttackRangeDefault ;
};

#endif

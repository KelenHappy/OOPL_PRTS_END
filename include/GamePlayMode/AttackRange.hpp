#ifndef ATTACK_RANGE_HPP
#define ATTACK_RANGE_HPP

#include "Block.hpp"
#include <iostream>
#include <memory>
#include <vector>

class AttackRange {
public:
	void SetAttackRangeNum(int Range){
		AttackRangeNum = Range;
	}
	
	int GetAttackRangeNum(){
		return AttackRangeNum;
	}
    void SetAttackRangeNow(std::shared_ptr<std::vector<Block>> Range) {
        if (Range) {  // 避免空指針
            AttackRangeNow = std::make_shared<std::vector<Block>>(*Range); // 複製 vector 數據
        }
    }

    void SetAttackRangeDefault(std::shared_ptr<std::vector<Block>> Range) {
        if (Range) {
            AttackRangeDefault = std::make_shared<std::vector<Block>>(*Range);
        }
    }

    // 修正：確保 m_DefaultRange 初始化後再 push_back
    void SetDefaultRange() {
        if (!m_DefaultRange) {
            m_DefaultRange = std::make_shared<std::vector<std::vector<std::string>>>();
        }

        for (int i = 0; i < 5; i++) {
            m_DefaultRange->push_back(std::vector<std::string>(5, "0"));
        }
    }

    void SetNowRange(std::shared_ptr<std::vector<std::vector<std::string>>> In) {
        m_DefaultRange = In;
    }
	
protected:
	int AttackRangeNum = 0 ;
    std::shared_ptr<std::vector<std::vector<std::string>>> m_DefaultRange;
    std::shared_ptr<std::vector<Block>> AttackRangeNow = nullptr;
    std::shared_ptr<std::vector<Block>> AttackRangeDefault = nullptr;
};

#endif

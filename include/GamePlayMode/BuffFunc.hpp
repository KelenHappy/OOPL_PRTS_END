#ifndef BUFF_FUNC_HPP
#define BUFF_FUNC_HPP
#include "GamePlayMode/BuffType.hpp"
#include <iostream>
template <typename T1, typename T2>
void BuffFunc(T1 thisC, T2 that){
	if(thisC == nullptr or that == nullptr){
		std::cout << "Attack Error" << std::endl;
	}
    for(size_t i = 0; i < thisC->bufftype.size(); i++){
        switch(thisC->bufftype[i]){
            case BuffType::Attack:

                break;
            case BuffType::Defend:

                break;
            case BuffType::Health:

                break;
            case BuffType::AttackSpeed:

                break;
            default:
                std::cout << "Error Buff" << std::endl;
                break;
        }
    }
}
#endif

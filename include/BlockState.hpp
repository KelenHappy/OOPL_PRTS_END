//
// Created by AaronChiu on 2025/3/14.
//

#ifndef BLOCKSTATE_HPP
#define BLOCKSTATE_HPP
enum class BlockState {
    HIGH,     // 高台
    GROUND,   // 地面
    BOTH,    // 高台與地面
    NONE     //無法放置
};
#endif //BLOCKSTATE_HPP

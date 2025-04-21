#ifndef CHARACTER_STATE_HPP
#define CHARACTER_STATE_HPP

// 角色的狀態
enum class CharacterState {
    Idle,     // 角色靜止
    Attack,   // 角色攻擊
    Die,      // 角色死亡
    Start,    // 角色開始動畫
	HalfCard,
    Default   // 預設狀態
};
#endif // CHARACTER_STATE_HPP

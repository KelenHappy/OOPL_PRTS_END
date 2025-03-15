#ifndef ENEMY_STATE_HPP
#define ENEMY_STATE_HPP

// 角色的狀態
enum class EnemyState {
    Idle,     // 角色靜止
    Attack,   // 角色攻擊
    Die,      // 角色死亡
    Move,    // 角色開始動畫
    Default   // 預設狀態
};

enum class AttackType {
	Magic,
	Physics
};

#endif // ENEMY_STATE_HPP

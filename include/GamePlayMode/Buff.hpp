#ifndef BUFF_HPP
#define BUFF_HPP

#include "Util/GameObject.hpp"
#include <vector>

class Buff {
public:
  Buff() {}

  // 設定是否處於 Buff 狀態
  void SetGetBuff(bool enable) {
    GetBuff = enable;
  }

  // 每次遊戲更新時調用
  void Update() {
    if (BuffTT) {
      NowTicks++;
      if (NowTicks >= MaxTicks) {
        ClearBuff();
      }
    }
  }

  // 清除 Buff
  void ClearBuff() {
    BuffTT = false;

    GAttackBuff = 1;
    GDefendBuff = 1;
    GAttackSpeedBuff = 1;
    GHealthBuff = 1;

    NowTicks = 0;
    MaxTicks = 0;
  }

  // 檢查是否正在 Buff 中
  bool IsBuffActive() const {
    return BuffTT;
  }

  ~Buff() {}

protected:
  bool GetBuff = false;               // 是否允許 Buff（可作為角色可被 Buff 條件）
  bool BuffTT = false;                // 是否正在 Buff 狀態

  int GAttackBuff = 1;
  int GDefendBuff = 1;
  int GAttackSpeedBuff = 1;
  int GHealthBuff = 1;

  int NowTicks = 0;                  // 當前 Buff 經過的時間
  int MaxTicks = 0;                  // Buff 持續的時間
};

#endif // BUFF_HPP

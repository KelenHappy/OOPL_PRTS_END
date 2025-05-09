#ifndef BUFF_HPP
#define BUFF_HPP

#include "GamePlayMode/BuffType.hpp"
#include "Util/GameObject.hpp"
#include <vector>

class Buff {
public:
  Buff() {}

  // 設定是否處於 Buff 狀態
  void SetGetBuff(bool enable) {
    GetBuff = enable;
  }

  // 設定 Buff，傳入持續時間（Tick 數）與 Buff 效果（例如攻擊力加成等）
  void ApplyBuff(const std::vector<int>& buffData, int durationTicks) {
    BuffTT = true;
    BuffInfo = buffData;
    MaxTicks = durationTicks;
    NowTicks = 0;
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
    BuffInfo.clear();
    NowTicks = 0;
    MaxTicks = 0;
  }

  // 檢查是否正在 Buff 中
  bool IsBuffActive() const {
    return BuffTT;
  }

  // 取得 Buff 資訊（可用來計算攻擊力、防禦力等）
  std::vector<int> GetBuffInfo() const {
    return BuffInfo;
  }

  ~Buff() {}

protected:
  bool GetBuff = false;               // 是否允許 Buff（可作為角色可被 Buff 條件）
  bool BuffTT = false;                // 是否正在 Buff 狀態
  std::vector<int> BuffInfo;         // Buff 效果資料（如：攻擊加成、移速等）
  std::vector<BuffType> bufftype;
  int NowTicks = 0;                  // 當前 Buff 經過的時間
  int MaxTicks = 0;                  // Buff 持續的時間
};

#endif // BUFF_HPP

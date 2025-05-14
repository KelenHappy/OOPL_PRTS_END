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
  void SetBuffTime(int time){
      MaxTicks = time;
  }
  void SetInfoForBuffU(float ab, float db, float asb, float hpb){
      AttackBB = ab;
      DefendBB = db;
      AttackSpeedBB = asb;
      HPBB = hpb;
  }
  // 每次遊戲更新時調用
  void UpdateBuffTime() {
      NowTicks++;
      if (NowTicks >= MaxTicks) {
        ClearBuff();
      }
  }

  // 清除 Buff
  void ClearBuff() {

    GAttackBuff = 1;
    GDefendBuff = 1;
    GAttackSpeedBuff = 1;
    GHealthBuff = 1;

    NowTicks = 0;
    MaxTicks = 0;
  }

  ~Buff() {}

protected:
  bool GetBuff = false;               // 是否允許 Buff（可作為角色可被 Buff 條件）

  int GAttackBuff = 1;
  int GDefendBuff = 1;
  int GAttackSpeedBuff = 1;
  int GHealthBuff = 1;

  int NowTicks = 0;                  // 當前 Buff 經過的時間
  int MaxTicks = 0;                  // Buff 持續的時間
  //int attack, int defend, int attackspeed, int hp
  float AttackBB = 1;
  float DefendBB = 1;
  float AttackSpeedBB = 1;
  float HPBB = 1;

};

#endif // BUFF_HPP

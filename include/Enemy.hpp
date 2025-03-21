#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "AnimatedEnemy.hpp"
#include <set>
class Enemy : public AnimatedEnemy{
public:
    Enemy(std::string EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont) : AnimatedEnemy(){
			int defaultNum = 24; 
            DefaultImage.reserve(1);
            DefaultImage.emplace_back(RESOURCE_DIR"/Enemy/"+EnemyName+"/Default/1.png");
            IdleImage.reserve(defaultNum + 6);
            MoveImage.reserve(defaultNum + 6);
            DieImage.reserve(defaultNum + 6);
            AttackImage.reserve(defaultNum + 6);
            for(float i = 0; i < IdleCont; i += (float)IdleCont / defaultNum){
				std::set<int> seen;
				int int_i = static_cast<int>(i);  // 強制轉為 int
				if (seen.find(int_i) != seen.end()) {
					continue;  // 如果已經出現過該值，跳過這次循環
				}
                IdleImage.emplace_back(RESOURCE_DIR"/Enemy/"+EnemyName+"/Idle/"+std::to_string(int_i+1)+".png");
            }
            for(float i = 0; i < MoveCont; i += (float)MoveCont / defaultNum){
				std::set<int> seen;
				int int_i = static_cast<int>(i);  // 強制轉為 int
				if (seen.find(int_i) != seen.end()) {
					continue;  // 如果已經出現過該值，跳過這次循環
				}
                MoveImage.emplace_back(RESOURCE_DIR"/Enemy/"+EnemyName+"/Move/"+std::to_string(int_i+1)+".png");
            }
            for(float i = 0; i < DieCont; i += (float)DieCont / defaultNum){
				std::set<int> seen;
				int int_i = static_cast<int>(i);  // 強制轉為 int
				if (seen.find(int_i) != seen.end()) {
					continue;  // 如果已經出現過該值，跳過這次循環
				}
                DieImage.emplace_back(RESOURCE_DIR"/Enemy/"+EnemyName+"/Die/"+std::to_string(int_i+1)+".png");
            }
            for(float i = 0; i < AttackCont; i += (float)AttackCont / defaultNum){
				std::set<int> seen;
				int int_i = static_cast<int>(i);  // 強制轉為 int
				if (seen.find(int_i) != seen.end()) {
					continue;  // 如果已經出現過該值，跳過這次循環
				}
                AttackImage.emplace_back(RESOURCE_DIR"/Enemy/"+EnemyName+"/Attack/"+std::to_string(int_i+1)+".png");
            }
            SetPath(IdleImage, AttackImage, DieImage, MoveImage, DefaultImage);

    }
	
	void SetInfo(int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
	, float AttackDistance, int AttackCastle, float MoveSpeed, int HeavyLevel, int HealthRecover
	, bool Dizzy, bool Sleep, bool Frozen
	, AttackType attack_t){
		HealthNum = Health;
		AttackNum = Attack;
		DefendNum = Defend;
		MagicDefendNum = MagicDefend;
		AttackSpeedNum = AttackSpeed;
		AttackDistanceNum = AttackDistance;
		AttackCastleNum = AttackCastle;
		MoveSpeedNum = MoveSpeed;
		HeavyLevelNum = HeavyLevel;
		HealthRecoverNum = HealthRecover;
		DizzyDefend = Dizzy;
		SleepDefend = Sleep;
		FrozenDefend = Frozen;
		attack_type = attack_t;
	}
	~Enemy(){}
protected:
	std::vector<std::string> DefaultImage;
	std::vector<std::string> IdleImage;
	std::vector<std::string> MoveImage;
	std::vector<std::string> AttackImage;
	std::vector<std::string> DieImage;
	// 角色數值
	int HealthNum = 0;
	int AttackNum = 0;
	int DefendNum = 0;
	int MagicDefendNum = 0;
	int AttackSpeedNum = 0;
	float AttackDistanceNum = 0;
	int AttackCastleNum = 0;
	float MoveSpeedNum = 0.0;
	int HeavyLevelNum = 0;
	int HealthRecoverNum = 0;

	bool DizzyDefend = false;
	bool SleepDefend = false;
	bool FrozenDefend = false;

	AttackType attack_type = AttackType::Physics;

};

#endif

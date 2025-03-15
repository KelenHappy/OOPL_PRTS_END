#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "AnimatedEnemy.hpp"
class Enemy : public AnimatedEnemy{
public:
    Enemy(std::string EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont) : AnimatedEnemy(){
            DefaultImage.reserve(1);
            DefaultImage.emplace_back(RESOURCE_DIR"/Enemy/"+EnemyName+"/Default/1.png");
            IdleImage.reserve(IdleCont);
            MoveImage.reserve(MoveCont);
            DieImage.reserve(DieCont);
            AttackImage.reserve(AttackCont);
            for(int i = 0; i < IdleCont; ++i){
                IdleImage.emplace_back(RESOURCE_DIR"/Enemy/"+EnemyName+"/Idle/"+std::to_string(i+1)+".png");
            }
            for(int i = 0; i < MoveCont; ++i){
                MoveImage.emplace_back(RESOURCE_DIR"/Enemy/"+EnemyName+"/Move/"+std::to_string(i+1)+".png");
            }
            for(int i = 0; i < DieCont; ++i){
                DieImage.emplace_back(RESOURCE_DIR"/Enemy/"+EnemyName+"/Die/"+std::to_string(i+1)+".png");
            }
            for(int i = 0; i < AttackCont; ++i){
                AttackImage.emplace_back(RESOURCE_DIR"/Enemy/"+EnemyName+"/Attack/"+std::to_string(i+1)+".png");
            }
            SetPath(IdleImage, AttackImage, DieImage, MoveImage, DefaultImage);

    }
	
	void SetInfo(int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
	, int AttackDistance, int AttackCastle, int MoveSpeed, int HeavyLevel, int HealthRecover
	, bool Dizzy, bool Sleep, bool Frozen,
	AttackType attack_t){
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
	
private:
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
	int AttackDistanceNum = 0;
	int AttackCastleNum = 0;
	int MoveSpeedNum = 0;
	int HeavyLevelNum = 0;
	int HealthRecoverNum = 0;

	bool DizzyDefend = false;
	bool SleepDefend = false;
	bool FrozenDefend = false;

	AttackType attack_type = AttackType::Physics;

};

#endif

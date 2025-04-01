#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "AnimatedEnemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
#include "GamePlayMode/CharacterSkill.hpp"
#include <set>

class Enemy : public AnimatedEnemy, public CharacterSkill{
public:
    Enemy(std::string EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont) : AnimatedEnemy(){
			int defaultNum = 10; 
            DefaultImage.reserve(1);
            DefaultImage.emplace_back(RESOURCE_DIR"/Enemy/"+EnemyName+"/Default/1.png");
            IdleImage.reserve(defaultNum + 2);
            MoveImage.reserve(defaultNum + 2);
            DieImage.reserve(defaultNum + 2);
            AttackImage.reserve(defaultNum + 2);
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
	// Function
	void takeDamage(CharacterAttackImpact impact, float damage);
	void ImpactDizzy();
	void ImpactSleep();
	void ImpactFrozen();
	void ApplySkillEffects();
	void CloseSkill();
	// Set
		void SetImageSize(float x, float y){
		m_Transform.scale={x, y}; 
	}
	void SetInfo(int Health, int Attack, int Defend, int MagicDefend, int AttackSpeed
	, float AttackDistance, int AttackCastle, float MoveSpeed, int HeavyLevel, int HealthRecover
	, bool Dizzy, bool Sleep, bool Frozen
	, CharacterAttackType attack_t){
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
		AttackType = attack_t;
	}
	
	// Get
	int GetHP(){
		return HealthNum;
	}
	float GetAttack() { 
		return AttackNum;
	}
	float GetDefend() { 
		return DefendNum;
	}
	float GetMagicDefend() { 
		return MagicDefendNum;
	}
	float GetAttackSpeed(){
		return AttackSpeedNum;
	}
	float GetAttackDistance(){	
		return AttackDistanceNum;
	}
	int GetAttackCastle(){	
		return AttackCastleNum;
	}
	float GetMoveSpeed(){
		return MoveSpeedNum;
	}
	int GetHeavyLevel(){
		return HeavyLevelNum;
	}
	int GetHealthRecover(){
		return HealthRecoverNum;
	}
	bool GetDizzyDefend(){
		return DizzyDefend;
	}
	bool GetSleepDefend(){
		return SleepDefend;
	}
	bool GetFrozenDefend(){
		return FrozenDefend;
	}

	CharacterAttackImpact GetAttackImpact(){
		return AttackImpact;
	}
    CharacterAttackType GetAttackType(){
		return AttackType;
	}
	
	std::string GetJob(){
		return "Enemy";
	}
	
	~Enemy(){}
protected:
	std::vector<std::string> DefaultImage;
	std::vector<std::string> IdleImage;
	std::vector<std::string> MoveImage;
	std::vector<std::string> AttackImage;
	std::vector<std::string> DieImage;
	// 角色數值
	float HealthNum = 0;
	float AttackNum = 0;
	float DefendNum = 0;
	float MagicDefendNum = 0;
	float AttackSpeedNum = 0;
	float AttackDistanceNum = 0;
	int AttackCastleNum = 0;
	float MoveSpeedNum = 0;
	int HeavyLevelNum = 0;
	int HealthRecoverNum = 0;

	bool DizzyDefend = false;
	bool SleepDefend = false;
	bool FrozenDefend = false;

	CharacterAttackType AttackType = CharacterAttackType::Physics;
	CharacterAttackImpact AttackImpact = CharacterAttackImpact::Null;

};

#endif

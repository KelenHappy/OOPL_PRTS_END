#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "AnimatedEnemy.hpp"
#include "GamePlayMode/CharacterAttackImpact.hpp"
#include "GamePlayMode/CharacterSkill.hpp"
#include <set>

#include "Hpbar.hpp"
#include "Pathpoints.hpp"

class Enemy : public AnimatedEnemy, public CharacterSkill,public std::enable_shared_from_this<Enemy>{
public:
    Enemy(std::string EnemyNameI, int IdleCont, int AttackCont,int DieCont, int MoveCont) : AnimatedEnemy(){
		int defaultNum = 10;
		EnemyName = EnemyNameI;
		DefaultImage.reserve(1);
		DefaultImage.emplace_back(RESOURCE_DIR"/Enemy/" + EnemyName + "/Default/1.png");

		IdleImage.reserve(defaultNum + 2);
		MoveImage.reserve(defaultNum + 2);
		DieImage.reserve(defaultNum + 2);
		AttackImage.reserve(defaultNum + 2);

		std::set<int> seen;

		// Idle
		seen.clear();
		for (float i = 0; i < IdleCont; i += (float)IdleCont / defaultNum) {
			int int_i = static_cast<int>(i);
			if (seen.find(int_i) != seen.end()) continue;
			seen.insert(int_i);
			IdleImage.emplace_back(RESOURCE_DIR"/Enemy/" + EnemyName + "/Idle/" + std::to_string(int_i + 1) + ".png");
		}

		// Move
		seen.clear();
		for (float i = 0; i < MoveCont; i += (float)MoveCont / defaultNum) {
			int int_i = static_cast<int>(i);
			if (seen.find(int_i) != seen.end()) continue;
			seen.insert(int_i);
			MoveImage.emplace_back(RESOURCE_DIR"/Enemy/" + EnemyName + "/Move/" + std::to_string(int_i + 1) + ".png");
		}

		// Die
		seen.clear();
		for (float i = 0; i < DieCont; i += (float)DieCont / defaultNum) {
			int int_i = static_cast<int>(i);
			if (seen.find(int_i) != seen.end()) continue;
			seen.insert(int_i);
			DieImage.emplace_back(RESOURCE_DIR"/Enemy/" + EnemyName + "/Die/" + std::to_string(int_i + 1) + ".png");
		}

		// Attack
		seen.clear();
		for (float i = 0; i < AttackCont; i += (float)AttackCont / defaultNum) {
			int int_i = static_cast<int>(i);
			if (seen.find(int_i) != seen.end()) continue;
			seen.insert(int_i);
			AttackImage.emplace_back(RESOURCE_DIR"/Enemy/" + EnemyName + "/Attack/" + std::to_string(int_i + 1) + ".png");
		}

		SetPath(IdleImage, AttackImage, DieImage, MoveImage, DefaultImage);
    	I_Hpbar=std::make_shared<HpBar>();
    	I_Hpbar->Update(HealthRecoverNum,HealthNum);
    	I_Hpbar->m_Transform.translation=GetPositionFix()-glm::vec2{ 0,13 };
    	I_Hpbar->SetVisible(false);
    }
	// Function
	void takeDamage(CharacterAttackImpact impact, float damage);
	void ImpactDizzy();
	void ImpactSleep();
	void ImpactFrozen();
	void ApplySkillEffects();
	void CloseSkill();
	void Updatemove();
	// Set
		void SetImageSize(float x, float y){
		m_Transform.scale={x, y}; 
	}
	void SetPathPoint(std::shared_ptr<PathPoints> P){PathPoint=P;}
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
		HealthNum = Health;
		HeavyLevelNum = HeavyLevel;
		HealthRecoverNum = Health;
		DizzyDefend = Dizzy;
		SleepDefend = Sleep;
		FrozenDefend = Frozen;
		AttackType = attack_t;
	}
	
	// Get
	std::shared_ptr<HpBar> GetHpBar(){return I_Hpbar;}
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
	int GetPathPointsindex(){return PathPointsindex;}
	void SetPathPointsindex(int n){PathPointsindex=n;}
	void AddPathPointsindex(){PathPointsindex++;}
	std::shared_ptr<PathPoints> GetPathPoints(){return PathPoint;}

	CharacterAttackImpact GetAttackImpact(){
		return AttackImpact;
	}
    CharacterAttackType GetAttackType(){
		return AttackType;
	}
	glm::vec2 GetPositionFix(){return  m_Transform.translation-glm::vec2{0,250*abs(m_Transform.scale.y)};}
	
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
	std::shared_ptr<PathPoints>  PathPoint;
	std::shared_ptr<HpBar> I_Hpbar;
	//Name
	std::string EnemyName = "";
	// 角色數值
	int PathPointsindex=0;
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

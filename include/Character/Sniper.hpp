#ifndef SNIPER_HPP
#define SNIPER_HPP
#include "AnimatedCharacter.hpp"

class Sniper : public AnimatedCharacter{
public:
    Sniper(std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont) : AnimatedCharacter(){
		int defaultNum = 25;
		
		SetCharacterName(CharacterName);

		HalfCardImage.emplace_back(RESOURCE_DIR"/HalfCard/Sniper/"+ CharacterName + ".png");
		DefaultImage.emplace_back(RESOURCE_DIR"/Character/Sniper/" + CharacterName + "/Default/1.png");
		this->m_HalfCard = std::make_shared<Util::Animation>(HalfCardImage, false, 40, false, 40);
		this->m_Drawable = std::make_shared<Util::Animation>(HalfCardImage, false, 40, false, 40);
		
		IdleImage.reserve(defaultNum);
		StartImage.reserve(defaultNum);
		DieImage.reserve(defaultNum);
		AttackImage.reserve(defaultNum);

		std::set<int> seen;

		// Idle
		seen.clear();
		for(float i = 0; i < IdleCont; i += (float)IdleCont / defaultNum){
			int int_i = static_cast<int>(i);
			if (seen.find(int_i) != seen.end()) continue;
			seen.insert(int_i);
			IdleImage.emplace_back(RESOURCE_DIR"/Character/Sniper/" + CharacterName + "/Idle/" + std::to_string(int_i + 1) + ".png");
		}

		// Start
		seen.clear();
		for(float i = 0; i < StartCont; i += (float)StartCont / defaultNum){
			int int_i = static_cast<int>(i);
			if (seen.find(int_i) != seen.end()) continue;
			seen.insert(int_i);
			StartImage.emplace_back(RESOURCE_DIR"/Character/Sniper/" + CharacterName + "/Start/" + std::to_string(int_i + 1) + ".png");
		}

		// Die
		seen.clear();
		for(float i = 0; i < DieCont; i += (float)DieCont / defaultNum){
			int int_i = static_cast<int>(i);
			if (seen.find(int_i) != seen.end()) continue;
			seen.insert(int_i);
			DieImage.emplace_back(RESOURCE_DIR"/Character/Sniper/" + CharacterName + "/Die/" + std::to_string(int_i + 1) + ".png");
		}

		// Attack
		seen.clear();
		for(float i = 0; i < AttackCont; i += (float)AttackCont / defaultNum){
			int int_i = static_cast<int>(i);
			if (seen.find(int_i) != seen.end()) continue;
			seen.insert(int_i);
			AttackImage.emplace_back(RESOURCE_DIR"/Character/Sniper/" + CharacterName + "/Attack/" + std::to_string(int_i + 1) + ".png");
		}
    }

	void CreateAnimation() override{
		SetPath(IdleImage, AttackImage, DieImage, StartImage, DefaultImage);
	}
	std::string GetJob() override{
		return "Sniper";
	}
	ClassState GetJobClass() override {
    	return ClassState::Sniper;
    }
	BlockState GetBlockState() override{
		return BlockState::HIGH;
	}
	
	~Sniper(){}
protected:
	std::vector<std::string> HalfCardImage;
	std::vector<std::string> DefaultImage;
	std::vector<std::string> IdleImage;
	std::vector<std::string> StartImage;
	std::vector<std::string> AttackImage;
	std::vector<std::string> DieImage;
};

#endif

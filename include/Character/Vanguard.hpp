#ifndef VANGUARD_HPP
#define VANGUARD_HPP
#include "AnimatedCharacter.hpp"


class Vanguard : public AnimatedCharacter{
public:
    Vanguard(std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont) : AnimatedCharacter(){
			int defaultNum = 30;
    		SetCharacterName(CharacterName);
            DefaultImage.reserve(1);
            DefaultImage.emplace_back(RESOURCE_DIR"/Character/Vanguard/"+CharacterName+"/Default/1.png");
            IdleImage.reserve(defaultNum + 2);
            StartImage.reserve(defaultNum + 2);
            DieImage.reserve(defaultNum + 2);
            AttackImage.reserve(defaultNum + 2);
            for(float i = 0; i < IdleCont; i += (float)IdleCont / defaultNum){
				std::set<int> seen;
				int int_i = static_cast<int>(i);  // 強制轉為 int
				if (seen.find(int_i) != seen.end()) {
					continue;  // 如果已經出現過該值，跳過這次循環
				}
                IdleImage.emplace_back(RESOURCE_DIR"/Character/Vanguard/"+CharacterName+"/Idle/"+std::to_string(int_i+1)+".png");
            }
            for(float i = 0; i < StartCont; i += (float)StartCont / defaultNum){
				std::set<int> seen;
				int int_i = static_cast<int>(i);  // 強制轉為 int
				if (seen.find(int_i) != seen.end()) {
					continue;  // 如果已經出現過該值，跳過這次循環
				}
                StartImage.emplace_back(RESOURCE_DIR"/Character/Vanguard/"+CharacterName+"/Start/"+std::to_string(int_i+1)+".png");
            }
            for(float i = 0; i < DieCont; i += (float)DieCont / defaultNum){
				std::set<int> seen;
				int int_i = static_cast<int>(i);  // 強制轉為 int
				if (seen.find(int_i) != seen.end()) {
					continue;  // 如果已經出現過該值，跳過這次循環
				}
                DieImage.emplace_back(RESOURCE_DIR"/Character/Vanguard/"+CharacterName+"/Die/"+std::to_string(int_i+1)+".png");
            }
            for(float i = 0; i < AttackCont; i += (float)AttackCont / defaultNum){
				std::set<int> seen;
				int int_i = static_cast<int>(i);  // 強制轉為 int
				if (seen.find(int_i) != seen.end()) {
					continue;  // 如果已經出現過該值，跳過這次循環
				}
                AttackImage.emplace_back(RESOURCE_DIR"/Character/Vanguard/"+CharacterName+"/Attack/"+std::to_string(int_i+1)+".png");
            }
            SetPath(IdleImage, AttackImage, DieImage, StartImage, DefaultImage);

    }
	
	std::string GetJob() override{
		return "Vanguard";
	}
	ClassState GetJobClass() override {
	    return ClassState::Vanguard;
    }
	BlockState GetBlockState() override{
		return BlockState::GROUND;
	}
	~Vanguard(){}
protected:
	
	std::vector<std::string> DefaultImage;
	std::vector<std::string> IdleImage;
	std::vector<std::string> StartImage;
	std::vector<std::string> AttackImage;
	std::vector<std::string> DieImage;
};

#endif

#ifndef MEDIC_HPP
#define MEDIC_HPP
#include "AnimatedCharacter.hpp"
class Medic : public AnimatedCharacter{
public:
    Medic(std::string CharacterName, int IdleCont, int AttackCont,int DieCont, int StartCont) : AnimatedCharacter(){
            DefaultImage.reserve(1);
            DefaultImage.emplace_back(RESOURCE_DIR"/Character/Medic/"+CharacterName+"/Default/1.png");
            IdleImage.reserve(IdleCont);
            StartImage.reserve(StartCont);
            DieImage.reserve(DieCont);
            AttackImage.reserve(AttackCont);
            for(int i = 0; i < IdleCont; ++i){
                IdleImage.emplace_back(RESOURCE_DIR"/Character/Medic/"+CharacterName+"/Idle/"+std::to_string(i+1)+".png");
            }
            for(int i = 0; i < StartCont; ++i){
                StartImage.emplace_back(RESOURCE_DIR"/Character/Medic/"+CharacterName+"/Start/"+std::to_string(i+1)+".png");
            }
            for(int i = 0; i < DieCont; ++i){
                DieImage.emplace_back(RESOURCE_DIR"/Character/Medic/"+CharacterName+"/Die/"+std::to_string(i+1)+".png");
            }
            for(int i = 0; i < AttackCont; ++i){
                AttackImage.emplace_back(RESOURCE_DIR"/Character/Medic/"+CharacterName+"/Attack/"+std::to_string(i+1)+".png");
            }
            SetPath(IdleImage, AttackImage, DieImage, StartImage, DefaultImage);

    }

private:
std::vector<std::string> DefaultImage;
std::vector<std::string> IdleImage;
std::vector<std::string> StartImage;
std::vector<std::string> AttackImage;
std::vector<std::string> DieImage;
};

#endif

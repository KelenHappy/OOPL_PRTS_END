#ifndef SUPPORTER_HPP
#define SUPPORTER_HPP
#include "AnimatedCharacter.hpp"

class Supporter : public AnimatedCharacter{
public:
	Supporter(std::string CharacterName, int IdleCont, int AttackCont, int DieCont, int StartCont) : AnimatedCharacter() {
		int defaultNum = 25;

		SetCharacterName(CharacterName);
		SetAttackType(CharacterAttackType::Magic);

		HalfCardImage.emplace_back(RESOURCE_DIR "/HalfCard/Supporter/" + CharacterName + ".png");
		DefaultImage.emplace_back(RESOURCE_DIR "/Character/Supporter/" + CharacterName + "/Default/1.png");
		this->m_HalfCard = std::make_shared<Util::Animation>(HalfCardImage, false, 40, false, 40);
		this->m_Drawable = std::make_shared<Util::Animation>(HalfCardImage, false, 40, false, 40);

		IdleImage.reserve(defaultNum);
		StartImage.reserve(defaultNum);
		DieImage.reserve(defaultNum);
		AttackImage.reserve(defaultNum);

		std::set<int> seen;

		auto fillImages = [&](int count, std::vector<std::string>& images, const std::string& actionFolder) {
			seen.clear();
			for (int step = 0; step < defaultNum; ++step) {
				int idx = static_cast<int>(step * (float)count / defaultNum);
				if (seen.find(idx) != seen.end()) continue;
				seen.insert(idx);
				images.emplace_back(RESOURCE_DIR "/Character/Supporter/" + CharacterName + "/" + actionFolder + "/" + std::to_string(idx + 1) + ".png");
			}
		};

		fillImages(IdleCont, IdleImage, "Idle");
		fillImages(StartCont, StartImage, "Start");
		fillImages(DieCont, DieImage, "Die");
		fillImages(AttackCont, AttackImage, "Attack");
	}


	void CreateAnimation() override{
		SetPath(IdleImage, AttackImage, DieImage, StartImage, DefaultImage);
	}
	std::string GetJob() override{
		return "Supporter";
	}
	ClassState GetJobClass() override {
    	return ClassState::Supporter;
    }

	BlockState GetBlockState() override{
		return BlockState::HIGH;
	}
	~Supporter(){}
protected:
	std::vector<std::string> HalfCardImage;
	std::vector<std::string> DefaultImage;
	std::vector<std::string> IdleImage;
	std::vector<std::string> StartImage;
	std::vector<std::string> AttackImage;
	std::vector<std::string> DieImage;
};

#endif

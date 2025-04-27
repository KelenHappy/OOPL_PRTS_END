#ifndef APP_HPP
#define APP_HPP

#include "Film/Film.hpp"
#include "FlyUI.hpp"
#include "MainScream.hpp"
#include "ChooseCharacter/ChosenCharacter.hpp"
#include "Map.hpp"
#include "Util/Renderer.hpp"
#include "Card/HalfCard.hpp"
#include "Character/AnimatedCharacter.hpp"
#include "Character/CharacterState.hpp"
#include "GameTimer.hpp"
#include "Hpbar.hpp"
#include "MobSpawner.hpp"
#include "Character/Medic.hpp"
#include "Character/Sniper.hpp"
#include "Character/Vanguard.hpp"

#include "Character/Medic/Sussurro.hpp"
#include "Character/Medic/Warfarin.hpp"
#include "Character/Medic/Ptilopsis.hpp"

#include "Character/Sniper/Exudiai.hpp"
#include "Character/Sniper/Kroos.hpp"
#include "Character/Sniper/W.hpp"

#include "Character/Vanguard/Texas.hpp"
#include "Character/Vanguard/Ines.hpp"
#include "Character/Vanguard/Myrtle.hpp"

#include "Enemy/Enemy.hpp"
#include "Enemy/EnemyState.hpp"
#include "Enemy/BugA.hpp"
#include "Enemy/Soldier.hpp"
#include "Enemy/Thrower.hpp"
#include "Enemy/Varlorant.hpp"

#include "GamePlayMode/Attack.hpp"

class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };
    enum class level {
        lobby,
        main17,
        cc5,
        rog53,
		chooseCharacter
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)
	~App(){}
private:
    void ValidTask();
    bool checkCollisionNearMouse(Util::Transform Mouse, Util::Transform Item, int range);
    void Debug();
	void ChooseCharacter();
    void LevelMain17();
    double calculateDistance(Util::Transform a, Util::Transform b);
	void Map0107Loading();
    void GameTick();
	void GameSecondTick();
	void PlaceCharacter(std::shared_ptr<Block> block,std::shared_ptr<AnimatedCharacter> Char );
	void choicemap();
	bool checkCollision(glm::vec2 cursorPos, glm::vec2 itemPos, float rangeX, float rangeY);

private:

    level m_level=level::lobby;
    State m_CurrentState = State::START;
    // 場景
    std::shared_ptr<MainScream> m_MainScream;
	std::shared_ptr<ChosenCharacter> m_ChosenCharacter;
    std::shared_ptr<TextBox> m_TT;
    std::shared_ptr<Map> m_map0107;
    std::shared_ptr<GameTimer> gametimer;
	std::shared_ptr<FlyUI>m_flyUI;
    Util::Renderer m_Root;
    Util::Renderer m_0107;
	Util::Renderer m_HalfCardScreen;
	Util::Renderer m_cc5;
	Util::Renderer m_rog53;
    // Character
    //Medic
	/*
	std::shared_ptr<Sussurro> m_Sussurro;
	std::shared_ptr<Warfarin> m_Warfarin;
    std::shared_ptr<Ptilopsis> m_Ptilopsis;

    //Sniper
	std::shared_ptr<Exusiai> m_Exusiai;
    std::shared_ptr<Kroos> m_Kroos;
    std::shared_ptr<W> m_W;
	
    //Vanguard
	std::shared_ptr<Texas> m_Texas;
    std::shared_ptr<Ines> m_Ines;
    std::shared_ptr<Myrtle> m_Myrtle;
    */

    //Enemies
	std::shared_ptr<Spawner> m_Spawner;
    //Charcter Choosen
	std::vector<std::shared_ptr<AnimatedCharacter>> m_StartCharacter;
	std::vector<std::shared_ptr<AnimatedCharacter>> m_LevelCharacter;
	// Enemy
    // idle attack die move
    std::vector<std::shared_ptr<Enemy>> Enemies;
    // 大便
	bool ckicking=false;
	bool CheckCard = false;
    bool carry=false;
	bool CheckCharacter = false;
    int m_Carry=-1;
	int m_CardCarry = -1;
	int m_CharacterCarry = -1;
	int Tickcount=0;
};

#endif

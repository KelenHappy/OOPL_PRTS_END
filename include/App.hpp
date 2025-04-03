#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export
#include "MainScream.hpp"
#include "Map.hpp"
#include "Util/Renderer.hpp"

#include "Character/AnimatedCharacter.hpp"
#include "Character/CharacterState.hpp"
#include "GameTimer.hpp"
#include "Character/Medic.hpp"
#include "Character/Sniper.hpp"
#include "Character/Vanguard.hpp"

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
    void LevelMain17();
    double calculateDistance(Util::Transform a, Util::Transform b);
	void Map0107Loading();
    void GameTick();


private:

    level m_level=level::lobby;
    State m_CurrentState = State::START;
    // 場景
    std::shared_ptr<MainScream> m_MainScream;
    std::shared_ptr<TextBox> m_TT;
    std::shared_ptr<Map> m_map0107;
    std::shared_ptr<GameTimer> gametimer;
    Util::Renderer m_Root;
    Util::Renderer m_0107;
    // Character
	std::shared_ptr<Medic> m_Sussurro;
	std::shared_ptr<Sniper> m_Exudiai;
	std::shared_ptr<Vanguard> m_Texas;
    //Charcter Choosen
	std::vector<std::shared_ptr<AnimatedCharacter>> m_StartCharacter;
	std::vector<std::shared_ptr<AnimatedCharacter>> m_LevelCharacter;
	// Enemy
    // idle attack die move
    std::vector<std::shared_ptr<BugA>> m_BugAs;
    std::vector<std::shared_ptr <Soldier>> m_Soldiers;
    std::vector<std::shared_ptr <Thrower>> m_Throwers;
    std::vector<std::shared_ptr <Varlorant>> m_Varlorants;
    // 大便
	bool CheckCard = false;
    bool carry=false;
	bool CheckCharacter = false;
    int m_Carry=-1;
	int m_CardCarry = -1;
	int m_CharacterCarry = -1;
};

#endif

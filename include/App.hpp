#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export
#include "MainScream.hpp"
#include "Map.hpp"
#include "Util/Renderer.hpp"
#include "AnimatedCharacter.hpp"
#include "AnimatedEnemy.hpp"
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

private:
    void ValidTask();

private:
    level m_level=level::lobby;
    State m_CurrentState = State::START;
    std::shared_ptr<MainScream> m_MainScream;
    std::shared_ptr<TextBox> m_TT;
    std::shared_ptr<Map> m_map0107;
    Util::Renderer m_Root;
    Util::Renderer m_0107;
};

#endif

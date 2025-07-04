#include "App.hpp"
#include "Util/Transform.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <vector>
void App::MapStart() {
    m_map0107=std::make_shared<Map>(m_MainScream->GetMapchoice());
    m_0107.AddChildren(m_map0107->GetChildren());
    //加載敵人

    m_Spawner=std::make_shared<Spawner>(m_MainScream->GetMapchoice());
    Enemies=m_Spawner->GetEnemies();
    m_0107.AddChildren(m_Spawner->GetEnemiesGameobject());
    for (size_t i = 0; i < Enemies.size(); i++){
        Enemies[i]->CreateAnimation();
    }
    // 特效加速
    m_FilmVector.clear();
    std::shared_ptr<Bullet> tempB = std::make_shared<Bullet> ("None", "Bullet");
    m_FilmVector.push_back(tempB);
    //
    m_map0107->SetEnemyTotalMax(m_Spawner->GetAllEnemycount());
    //角色選則

    for (size_t i = 0; i < m_LevelCharacter.size(); i++) {
        std::cout << "Get In Character " << m_LevelCharacter[i]->GetCharacterName() << std::endl;
        m_LevelCharacter[i]->CreateAnimation();
        m_LevelCharacter[i]->SetZIndex(15);
        m_LevelCharacter[i]->SetState(CharacterState::Default);
        m_LevelCharacter[i]->SetLooping(false);
        m_LevelCharacter[i]->SetVisible(false);
        m_LevelCharacter[i]->SetImageSize(0.25f, 0.25f);
        m_LevelCharacter[i]->SetPosition({575 - i*150, -289});
        m_LevelCharacter[i]->RestartOfStart();
        std::shared_ptr<Card> cd=std::make_shared<Card>(m_LevelCharacter[i]);
        cd->SetTranform(588-int(i*(144)/0.8*0.6),-318);
        m_map0107->AddCard(cd);
        m_0107.AddChild(m_LevelCharacter[i]);
        m_0107.AddChild(m_LevelCharacter[i]->Gethpbar());
        m_0107.AddChild(m_LevelCharacter[i]->GetMagicBar());
    }
    m_flyUI->SetVisible(false);
    m_0107.AddChildren(m_map0107->GetChildrenCard());
    m_0107.AddChild(m_flyUI);
    m_0107.AddChildren(m_placeUI->GetChildren());
    m_UIMapLevel=UIMapLevel::Main;
    gametimer->Start();
    NowMap=m_map0107;
}

//
// Created by AaronChiu on 2025/3/14.
//

#ifndef MAP_HPP
#define MAP_HPP
#include "Block.hpp"
#include "Card.hpp"
#include "CreateIMG.hpp"
#include "Util/GameObject.hpp"
class Map :public Util::GameObject{
    public:
    Map() ;
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        std::vector<std::shared_ptr<Util::GameObject>> result;
        for(size_t i=0;i<m_block.size();i++) {
            result.push_back(m_block[i]);
        }
        for(size_t i=0;i<m_Card.size();i++) {
            result.push_back(m_Card[i]);
            result.push_back(m_Card[i]->GetCardback());
            result.push_back(m_Card[i]->GetCosttext());
            result.push_back(m_Card[i]->Getclass());
        }
        result.push_back(m_Cost);
        result.push_back(m_PutLimit);
        result.push_back(m_PutlimitBar);
        //result.push_back(m_PutLimit);
        result.push_back(m_map);
        return result;
    }
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildrenCard() const {
        std::vector<std::shared_ptr<Util::GameObject>> result;
        for(size_t i=0;i<m_Card.size();i++) {
            result.push_back(m_Card[i]);
            result.push_back(m_Card[i]->GetCardback());
            result.push_back(m_Card[i]->GetCosttext());
            result.push_back(m_Card[i]->Getclass());
        }
        return result;
    }
    [[nodiscard]] std::vector<std::shared_ptr<Block>> Getblock() {return m_block;}
    [[nodiscard]] int GetTowerHP(){return TowerHP;}
    [[nodiscard]] void SetTowerHP(int hp) {TowerHP = hp;}
    [[nodiscard]] void EmenyEnterTower() {TowerHP--;}
     int GetEnemytotal(){return EnemyTotal;}
     int GetEnemytotalMax(){return EnemyTotalMax;}
     void SetEnemyTotalMax(int n){EnemyTotalMax=n;}
     void SetEnemyTotal(int n){EnemyTotal=n;}
     void EnemyDied(){EnemyTotal++;}
     int Getmapcost(){return cost;}
    void Setmapcost(int n){cost=n;}
    void AddCard(std::shared_ptr<Card> card) {
        m_Card.push_back(card);
    };
    void Update();
    void CreatotherItem();

    private:
    int TowerHP;
    int EnemyTotalMax;
    int EnemyTotal;
    int cost;
    int PutLimit;
    std::vector<std::shared_ptr<Block>>m_block;
    std::shared_ptr<CreateIMG> m_map;
    std::vector<std::shared_ptr<Card>>m_Card;
    std::shared_ptr<ImgItem> m_EmemyandHp;
    std::shared_ptr<ImgItem> m_CostBar;
    std::shared_ptr<ImgItem> m_PutlimitBar;
    std::shared_ptr<TextBox> m_PutLimit;
    std::shared_ptr<TextBox> m_Cost;



};
#endif //MAP_HPP

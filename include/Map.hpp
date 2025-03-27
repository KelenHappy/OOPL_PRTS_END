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
        result.push_back(m_map);
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

    private:
    int TowerHP;
    int EnemyTotalMax;
    int EnemyTotal;
    int cost;
    std::vector<std::shared_ptr<Block>>m_block;
    std::shared_ptr<CreateIMG> m_map;
    std::vector<std::shared_ptr<Card>>m_Card;

};
#endif //MAP_HPP

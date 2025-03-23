//
// Created by AaronChiu on 2025/3/14.
//

#ifndef MAP_HPP
#define MAP_HPP
#include "Block.hpp"
#include "CreateIMG.hpp"
#include "Util/GameObject.hpp"
class Map :public Util::GameObject{
    public:
    Map() ;
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        std::vector<std::shared_ptr<Util::GameObject>> result;
        for(int i=0;i<m_block.size();i++) {
            result.push_back(m_block[i]);
        }
        result.push_back(m_map);
        return result;
    }
    [[nodiscard]] std::vector<std::shared_ptr<Block>> Getblock() {return m_block;}
    [[nodiscard]] int GetTowerHP(){return TowerHP;}
    [[nodiscard]] void SetTowerHP(int hp) {TowerHP = hp;}
    [[nodiscard]] void EmenyEnterTower() {TowerHP--;}
    [[nodiscard]] int GetEnemytotal(){return EnemyTotal;}
    [[nodiscard]] int GetEnemytotalMax(){return EnemyTotalMax;}
    [[nodiscard]] void SetEnemyTotalMax(int n){EnemyTotalMax=n;}
    [[nodiscard]] void SetEnemyTotal(int n){EnemyTotal=n;}
    [[nodiscard]] void EnemyDied(){EnemyTotal++;}

    private:
    int TowerHP;
    int EnemyTotalMax;
    int EnemyTotal;
    std::vector<std::shared_ptr<Block>>m_block;
    std::shared_ptr<CreateIMG> m_map;
};
#endif //MAP_HPP

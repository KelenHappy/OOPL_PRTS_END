//
// Created by AaronChiu on 2025/3/14.
//

#ifndef MAP_HPP
#define MAP_HPP
#include "Block.hpp"
#include "Card.hpp"
#include "CreateIMG.hpp"
#include "Mapchoice.hpp"
#include "Util/GameObject.hpp"
#include "Enumclass/Direction.hpp"
class Map :public Util::GameObject{
    public:
    Map(Mapchoice Mc);
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const ;
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
	std::vector<std::shared_ptr<Card>> GetCard() {return m_Card;}
    [[nodiscard]] int GetTowerHP(){return TowerHP;}
    void SetTowerHP(int hp) {TowerHP = hp;}
    void EmenyEnterTower() {TowerHP--;}
    void Addmapcost(int n) {cost=std::min(cost+n,99);}
    [[nodiscard]] bool Takemapcost(int n);
     int GetEnemytotal(){return EnemyTotal;}
     int GetEnemytotalMax(){return EnemyTotalMax;}
     void SetEnemyTotalMax(int n){EnemyTotalMax=n;Update();}
     void SetEnemyTotal(int n){EnemyTotal=n;}
     void EnemyDied(){EnemyTotal++;Update();}
     int Getmapcost(){return cost;}
    void Setmapcost(int n){cost=n;}
    void AddCard(std::shared_ptr<Card> card) {
        m_Card.push_back(card);
    };
    void CreateMapchoice(Mapchoice Mc);
    std::vector<std::shared_ptr<Block>> GetTypeOfBlock(BlockState B);
    std::vector<std::shared_ptr<Block>> GetHaveCharacterBlock(BlockState B,bool HaveCharacter);
    std::shared_ptr<Block> XYGetBlock(int x,int y){return m_block[x+mapsize.x*y];}
    void Update();
    void CreatotherItem();
    void openMapblock(BlockState B);
    void closeMapblock();
    std::vector<std::shared_ptr<Block>> ExtractBlocksFromPattern(const std::vector<std::vector<std::string>>& range,
    int base_x, int base_y, Direction dir);
    glm::vec2 GetMapsize(){return mapsize;}
	~Map(){}


    private:
    void CreateMain0107();
    void CreateCC5();
    void CreateRog53();
    int TowerHP;
    int EnemyTotalMax;
    int EnemyTotal;
    int cost;
    int PutLimit;
    glm::vec2 mapsize;
    std::vector<std::shared_ptr<Block>>m_block;
    std::shared_ptr<CreateIMG> m_map;
    std::vector<std::shared_ptr<Card>>m_Card;
    std::shared_ptr<ImgItem> m_EmemyandHp;
    std::shared_ptr<ImgItem> m_CostBar;
    std::shared_ptr<ImgItem> m_PutlimitBar;
    std::shared_ptr<TextBox> m_PutLimit;
    std::shared_ptr<TextBox> m_Cost;
    std::shared_ptr<TextBox> m_HPText;
    std::shared_ptr<TextBox> m_EnemyText;


};
#endif //MAP_HPP

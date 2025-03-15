#ifndef BUGA_HPP
#define BUGA_HPP
#include "Enemy.hpp"
#include "AnimatedCharacter.hpp"
class BugA : public Enemy{
public:
    //              EnemyName, int IdleCont, int AttackCont,int DieCont, int MoveCont
    BugA() : Enemy("Bug_A", 119, 47, 31, 120){

    }



private:
	
};

#endif

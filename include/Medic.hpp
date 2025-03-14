#ifndef MEDIC_HPP
#define MEDIC_HPP
#include "AnimatedCharacter.hpp"
class Medic : public AnimatedCharacter{
public:
    Medic() :
          AnimatedCharacter(AnimationPaths, IdleEnd, AttackEnd, DieEnd, StartEnd, Default){

    }

private:

};

#endif

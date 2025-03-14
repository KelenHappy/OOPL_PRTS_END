#ifndef MEDIC_HPP
#define MEDIC_HPP
#include "AnimatedCharacter.hpp"
class Medic : public AnimatedCharacter{
public:
    Medic(const std::vector<std::string>& AnimationPaths,
          const std::vector<std::string>& IdleEnd = {},
          const std::vector<std::string>& AttackEnd = {},
          const std::vector<std::string>& DieEnd = {},
          const std::vector<std::string>& StartEnd = {},
          const std::vector<std::string>& Default= {}) :
          AnimatedCharacter(AnimationPaths, IdleEnd, AttackEnd, DieEnd, StartEnd, Default){

    }

private:

};

#endif

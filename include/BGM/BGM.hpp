#include "Util/BGM.hpp"
#include <iostream>
#include <string>

#ifndef BGM_HPP
#define BGM_HPP

class BGM : public Util::BGM {  // Corrected 'pubilc' to 'public'
    public:  // Added access specifier for constructor and destructor
        BGM(std::string BGM_PATH) : Util::BGM(BGM_PATH) {
            // Constructor implementation (if needed)
        }

        ~BGM() = default;  // Corrected destructor syntax
};

#endif // BGM_HPP

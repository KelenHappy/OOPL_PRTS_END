#include "Util/BGM.hpp"
#include <iostream>
#include <string>
#include <vector>

#ifndef BGM_HPP
#define BGM_HPP

class BGM : public Util::BGM {  // Corrected 'pubilc' to 'public'
    public:  // Added access specifier for constructor and destructor
        BGM(std::string BGM_PATH) : Util::BGM(BGM_PATH) {
            // Constructor implementation (if needed)
        }
        ~BGM() = default;  // Corrected destructor syntax
    private:
    std::string source = "Resource/music/";
    std::vector<std::string> m_File = {
        source+"1-7.mp3",
        source+"失控.mp3",
        source+"競技場1.mp3",
        source+"競技場2.mp3",
        source+"LOBBY.mp3",
    };
};

#endif // BGM_HPP

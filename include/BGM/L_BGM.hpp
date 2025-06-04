#ifndef L_BGM_HPP
#define L_BGM_HPP

#include "Util/BGM.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory> // for std::shared_ptr

class L_BGM {
public:
    L_BGM(const std::string& PATH) {
        m_Music = std::make_shared<Util::BGM>(PATH);
    }
    void Play(true){

    }
    ~L_BGM() = default;

private:
    std::string source = "Resource/music/";
    std::vector<std::string> m_File = {
        source + "1-7.mp3",
        source + "失控.mp3",
        source + "競技場1.mp3",
        source + "競技場2.mp3",
        source + "LOBBY.mp3",
    };

    std::shared_ptr<Util::BGM> m_Music;
};

#endif // L_BGM_HPP

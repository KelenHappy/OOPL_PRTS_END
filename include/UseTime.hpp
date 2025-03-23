#ifndef USETIME_HPP
#define USETIME_HPP

#include <Util/Time.hpp>
#include <iostream>

class UseTime {
public:
    void Update() {
        Util::Time::Update(); // 更新時間
        float deltaTime = Util::Time::GetDeltaTimeMs(); // 取得 Delta Time
        accumulatedTime += deltaTime;
        frameulatedTime+=deltaTime;
        //std::cout  << " processed. Delta Time: " << deltaTime << " ms" << std::endl;

        if (frameulatedTime>=50.0f) {
            frameulatedTime = 0.0f;
        }
        if (accumulatedTime >= 1000.0f) {

            accumulatedTime = 0.0f; // 重置計時
        }
    }
    
private:
    float accumulatedTime = 0.0f; // 用來計算 1 秒是否已過
    float frameulatedTime = 0.0f; // 用來計算 1 禎是否已過

};

#endif //USETIME_HPP
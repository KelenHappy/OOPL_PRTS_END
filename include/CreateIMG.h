//
// Created by AaronChiu on 2025/3/14.
//

#ifndef CREATEIMG_H
#define CREATEIMG_H
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class CreateIMG:public Util::GameObject {
public:
    CreateIMG(std::string phase,const int zind):GameObject(
            std::make_unique<Util::Image>(ImagePath(phase)), zind){
    }
private:
    inline std::string ImagePath(std::string phase) {
        return RESOURCE_DIR +phase;
    }
};

#endif //CREATEIMG_H

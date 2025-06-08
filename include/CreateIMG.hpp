//
// Created by AaronChiu on 2025/3/14.
//

#ifndef CREATEIMG_HPP
#define CREATEIMG_HPP
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class CreateIMG:public Util::GameObject {
public:
    CreateIMG(std::string phase,const int zind):GameObject(
            std::make_unique<Util::Image>(ImagePath(phase)), zind){
    }
    void SetNewIMGstd(std::string newImagePath) {
        auto imagePtr = std::static_pointer_cast<Util::Image>(m_Drawable);
        if (imagePtr) {
            imagePtr->SetImage(RESOURCE_DIR+newImagePath);
        }
    }
private:
    inline std::string ImagePath(std::string phase) {
        return RESOURCE_DIR +phase;
    }
};

#endif //CREATEIMG_HPP

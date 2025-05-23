//
// Created by AaronChiu on 2025/3/21.
//

#ifndef IMGITEM_HPP
#define IMGITEM_HPP
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
class ImgItem:public Util::GameObject{
    public:
    ImgItem(std::string Sw) {
        m_Drawable = std::make_shared<Util::Image>(RESOURCE_DIR+Sw);
    }
    void setsize(float x,float y) {
        m_Transform.scale={x, y};
    }
    void SetNewIMGstd(std::string newImagePath) {
        auto imagePtr = std::static_pointer_cast<Util::Image>(m_Drawable);
        if (imagePtr) {
            imagePtr->SetImage(RESOURCE_DIR+newImagePath);
        }
    }


};
#endif //IMGITEM_HPP

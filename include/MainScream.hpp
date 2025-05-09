

#ifndef MAINSCREAM_HPP
#define MAINSCREAM_HPP
#include "CreateIMG.hpp"
#include "TextBox.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Text.hpp"
#include "Mapchoice.hpp"
class MainScream:public Util::GameObject {
    public:
    MainScream() {
        this->m_background=std::make_shared<CreateIMG>("/MainScream/R.jpg",-10);
        this->m_start=std::make_shared<TextBox>(40);
        this->m_start->SetText("開始遊戲");
        this->m_start->SetPosition({415, 100});
        this->m_map0107=std::make_shared<TextBox>(40);
        this->m_map0107->SetText("主線 1-7");
        this->m_map0107->SetPosition({415, -50});
        this->m_cc5=std::make_shared<TextBox>(40);
        this->m_cc5->SetText("八號競技場");
        this->m_cc5->SetPosition({415, -100});
        this->m_rog53=std::make_shared<TextBox>(40);
        this->m_rog53->SetText("緊急失控");
        this->m_rog53->SetPosition({415, -150});
        this->m_info1=std::make_shared<TextBox>(40);
        this->m_info1->SetText("地圖選擇:");
        this->m_info1->SetPosition({415, 0});
        this->m_choice=std::make_shared<ImgItem>("/MainScream/choiceblock.png");
        this->m_choice->m_Transform.translation=m_map0107->m_Transform.translation-glm::vec2(8,0);
        mapchoice_=Mapchoice::main17;
    };
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        return {m_start, m_background,m_map0107,m_cc5,m_rog53,m_info1,m_choice};
    }
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetTextInfo() const {
        return {m_start,m_map0107,m_cc5,m_rog53};
    }

    void SetMap(Mapchoice mc) {
        switch (mc) {
            case Mapchoice::main17:
                this->m_choice->m_Transform.translation=m_map0107->m_Transform.translation-glm::vec2(8,0);
                mapchoice_=Mapchoice::main17;
                break;
            case Mapchoice::cc5:
                this->m_choice->m_Transform.translation=m_cc5->m_Transform.translation-glm::vec2(8,0);
                mapchoice_=Mapchoice::cc5;
                break;
            case Mapchoice::rog53:
                this->m_choice->m_Transform.translation=m_rog53->m_Transform.translation-glm::vec2(8,0);
                mapchoice_=Mapchoice::rog53;
                break;
            default:
                break;
        }

    }
    Mapchoice GetMapchoice() {return mapchoice_;}

    private:
    std::shared_ptr<TextBox> m_start;
    std::shared_ptr<TextBox> m_info1;
    std::shared_ptr<TextBox> m_map0107;
    std::shared_ptr<TextBox> m_cc5;
    std::shared_ptr<TextBox> m_rog53;
    std::shared_ptr<ImgItem> m_choice;
    Mapchoice mapchoice_;
    std::shared_ptr<CreateIMG> m_background;

};
#endif //MAINSCREAM_HPP

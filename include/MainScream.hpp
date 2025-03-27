

#ifndef MAINSCREAM_HPP
#define MAINSCREAM_HPP
#include "CreateIMG.hpp"
#include "TextBox.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Text.hpp"


class MainScream:public Util::GameObject {
    public:
    MainScream() {
        this->m_background=std::make_shared<CreateIMG>("/MainScream/R.jpg",-10);
        this->m_start=std::make_shared<TextBox>(40);
        this->m_start->SetText("開始遊戲");
        this->m_start->SetPosition({415, 100});

    };
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        return {m_start, m_background};
    }

    private:
    std::shared_ptr<TextBox> m_start;
    std::shared_ptr<CreateIMG> m_background;





};
#endif //MAINSCREAM_HPP

//
// Created by AaronChiu on 2025/3/7.
//

#ifndef PHASERESOURCEMANGER_H
#define PHASERESOURCEMANGER_H
class PhaseResourceManger {
    public:
    PhaseResourceManger();

    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        return {m_TaskText, m_Background};
    }

    void NextPhase();

    private:
    std::shared_ptr<TaskText> m_TaskText;
    std::shared_ptr<BackgroundImage> m_Background;

    int m_Phase = 1;
};

#endif //PHASERESOURCEMANGER_H

#include <cmath>
#include <glm/gtx/vector_angle.hpp>
class Bullet : public Film {
public:
    Bullet(std::string name, std::string ff) : Film(name, ff, FilmState::Bullet) {
        // 根據敵人位置計算移動方向

    }

    ~Bullet() = default;

    void Update() override {
        // 每次更新時減少生命
        AddLife(1);
        SetVisible(true);
        std::cout << GetNowLife() << std::endl;

        // 根據敵人位置計算移動方向
        glm::vec2 here = GetPosition();
        int distance = CalculateDistance(here, EnemyPath);
        int speed = 50;

        // 計算方向向量
        glm::vec2 direction = EnemyPath - here;

        // 如果子彈仍然有距離可行駛，則繼續更新位置
        if (distance > 1) {  // 這裡 1.0f 是一個閾值，當距離小於這個閾值時，視為已到達目標

            direction = glm::normalize(direction);  // 標準化方向向量
            // 更新子彈的位置
            glm::vec2 newPosition = here + direction * static_cast<float>(speed);  // 將speed轉換為float
            SetPosition(newPosition);
            m_Transform.rotation = glm::radians(angle);
        } else {
            // 當距離小於某個閾值時，停止並消失
            SetLifeTimes(0);  // 結束子彈生命週期
        }
    }

    void SetEnemyPoint(glm::vec2 EE) override{
        EnemyPath = EE;
        glm::vec2 here = GetPosition();
        int distance = CalculateDistance(here, EnemyPath);
        //std::cout << "Distance: " << distance << std::endl;
        int speed = 50;

        // 根據距離更新生命週期，這裡使用距離來確定時間
        SetLifeTimes(static_cast<int>(std::abs(distance / speed)));

        glm::vec2 direction = EnemyPath - here;
        direction = glm::normalize(direction);  // 標準化方向向量
        glm::vec2 dirA = glm::normalize(here);
        glm::vec2 dirB = glm::normalize(EnemyPath);
        float radians = glm::angle(dirA, dirB);
        angle = glm::degrees(radians*-1);
    }
    // 計算兩點之間的距離
    int CalculateDistance(const glm::vec2& point1, const glm::vec2& point2) {
        // 使用整數處理，將浮點數轉換為整數
        int dx = static_cast<int>(point2.x) - static_cast<int>(point1.x);
        int dy = static_cast<int>(point2.y) - static_cast<int>(point1.y);
        //std::cout << dx << " " << dy << std::endl;
        // 使用整數計算距離的平方
        return static_cast<int>(std::sqrt(dx * dx + dy * dy));
    }

private:
    float angle = 0;

};

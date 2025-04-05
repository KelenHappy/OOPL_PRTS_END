
#ifndef MOVE_HPP
#define MOVE_HPP
#include "Card.hpp"
#include "Util/GameObject.hpp"
template <typename T, typename = std::enable_if_t<std::is_base_of_v<Util::GameObject, T>>>
void moveGameObject(std::shared_ptr<T> obj, const glm::vec2& target, float stepSize) {
    glm::vec2 start = obj->m_Transform.translation;
    glm::vec2 direction = target - start;
    float distance = glm::length(direction);
    if (distance == 0.0f) {
        return;
    }
    direction = glm::normalize(direction);
    float moveStep = std::min(stepSize, distance);
    glm::vec2 newPos = start + direction * moveStep;

    obj->m_Transform.translation = newPos;
    //std::cout << "New position: (" << newPos.x << ", " << newPos.y << ")\n";
}
#endif //MOVE_HPP

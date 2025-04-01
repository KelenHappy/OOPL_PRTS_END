
#ifndef MOVE_HPP
#define MOVE_HPP
#include "Card.hpp"
#include "Util/GameObject.hpp"
template <typename T, typename = std::enable_if_t<std::is_base_of_v<Util::GameObject, T>>>
void moveGameObject(std::shared_ptr<T> a, std::shared_ptr<T> b, float c) {
    glm::vec2 start = a->m_Transform.translation;
    glm::vec2 end = b->m_Transform.translation;

    glm::vec2 direction = end - start;
    float distance = glm::length(direction);

    if (distance == 0.0f) {
        return;
    }
    direction = glm::normalize(direction);
    float stepSize = std::min(c, distance); // Avoid overshooting
    glm::vec2 newPos = start + direction * stepSize;
    a->m_Transform.translation = newPos;
    //std::cout << "New position: (" << newPos.x << ", " << newPos.y << ")\n";
}

#endif //MOVE_HPP

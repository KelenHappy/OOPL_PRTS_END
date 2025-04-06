//
// Created by Aaron on 2025/4/6.
//

#ifndef MYTOOL_HPP
#define MYTOOL_HPP
template <typename T>
double calculateDistance(const T& a, const T& b) {
    glm::vec2 diff = a.translation - b.translation;
    return glm::length(diff);
}

#endif //MYTOOL_HPP

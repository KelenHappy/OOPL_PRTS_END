//
// Created by Aaron on 2025/4/2.
//

#ifndef PATHPOINTS_HPP
#define PATHPOINTS_HPP
#include <vector>
#include <glm/vec2.hpp>

class PathPoints {
private:
    std::vector<glm::vec2> points;
    size_t currentIndex = 0;
public:

    void addPoint(const glm::vec2& point) {
        points.push_back(point);
    }
    void setPoint(std::vector<glm::vec2> P) {
        this->points = P;
    }
    glm::vec2 GetnowPoint() {
        return points[currentIndex];
    }
    glm::vec2 getNextPoint() {
        if (currentIndex < points.size()-1) {
            return points[currentIndex++];
        }
        return points.back(); // Return last point if at end
    }
};

#endif //PATHPOINTS_HPP

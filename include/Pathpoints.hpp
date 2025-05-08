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
    std::vector<int> WaitTime;
public:

    void addPoint(const glm::vec2& point,int Wt) {
        points.push_back(point);
        WaitTime.push_back(Wt);
    }
    void setPoint(std::vector<glm::vec2> P) {
        this->points = P;
    }
    void setWaitTime(std::vector<int> Wt) {
        this->WaitTime = Wt;
    }
    glm::vec2 GetStartPoint() {
        return points[0];
    }
    int GetStartWaitPoint() {
        return WaitTime[0];
    }
    int GetIndexWaitPoint(int index) {
        return WaitTime[index];
    }
    glm::vec2 GetindexPoint(int index) {
        return points[index];
    }
    glm::vec2 getEndPoint() {
        return points[points.size() - 1];
    }
    size_t GetPointsize() {return points.size();}
};

#endif //PATHPOINTS_HPP

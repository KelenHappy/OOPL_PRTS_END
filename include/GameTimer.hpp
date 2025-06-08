#include <chrono>

class GameTimer {
public:
    GameTimer() : mStartTime(), mPausedTime(0), mRunning(false) {}

    void Start() {
        if (!mRunning) {
            mStartTime = std::chrono::high_resolution_clock::now();
            mPausedTime = 0;
            mRunning = true;
        }
    }

    void Pause() {
        if (mRunning) {
            mPausedTime += std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::high_resolution_clock::now() - mStartTime).count();
            mRunning = false;
        }
    }

    void Resume() {
        if (!mRunning) {
            mStartTime = std::chrono::high_resolution_clock::now();
            mRunning = true;
        }
    }

    void Reset() {
        mStartTime = std::chrono::high_resolution_clock::now();
        mPausedTime = 0;
        mRunning = true;
    }

    double GetElapsedTime() const {
        if (mRunning) {
            return mPausedTime + std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::high_resolution_clock::now() - mStartTime).count();
        }
        return mPausedTime;
    }

    bool HasElapsed(double milliseconds) {
        if (mRunning) {return GetElapsedTime() >= milliseconds;}
        return false;
    }

private:
    std::chrono::high_resolution_clock::time_point mStartTime;
    double mPausedTime;
    bool mRunning;
};

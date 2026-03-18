#include <atomic>

struct Status {
    std::atomic<bool> isRunning;
    std::atomic<int> progress;
    std::atomic<bool> hasError;

    Status() : isRunning(false), progress(0), hasError(false) {}
};

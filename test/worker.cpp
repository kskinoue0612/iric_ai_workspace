#include "worker.h"
#include "status.h"

#include <chrono>
#include <thread>

Worker::Worker() {
    // Constructor implementation
}

Worker::~Worker() {
    // Destructor implementation
}

void Worker::doHeavyWork(Status& status) {
    status.isRunning = true;
    status.progress = 0;

    for (int i = 0; i <= 100; ++i) {
        // Simulate work by sleeping for a short duration
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status.progress = i;
    }

    status.isRunning = false;
}

void Worker::openProject(Status& status) {
    status.isRunning = true;
    status.progress = 0;

    for (int i = 0; i <= 100; ++i) {
        // Simulate work by sleeping for a short duration
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status.progress = i;
    }

    status.isRunning = false;
}

void Worker::saveProject(Status& status) {
    status.isRunning = true;
    status.progress = 0;

    for (int i = 0; i <= 100; ++i) {
        // Simulate work by sleeping for a short duration
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status.progress = i;
    }

    status.isRunning = false;
}

void Worker::importBigData(Status& status) {
    status.isRunning = true;
    status.progress = 0;

    for (int i = 0; i <= 100; ++i) {
        // Simulate work by sleeping for a short duration
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status.progress = i;
    }

    status.isRunning = false;
}

void Worker::processData(Status& status) {
    status.isRunning = true;
    status.progress = 0;

    for (int i = 0; i <= 100; ++i) {
        // Simulate work by sleeping for a short duration
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status.progress = i;
    }

    status.isRunning = false;
}


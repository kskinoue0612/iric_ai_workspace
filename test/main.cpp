#include <iostream>
#include <thread>
#include <chrono>
#include "worker.h"
#include "status.h"

int main(int argc, char *argv[]) {
    Status status;
    Worker worker;

    std::thread workerThread([&]() {
        worker.doHeavyWork(status);
    });

    while (status.isRunning || status.progress < 100) {
        std::cout << "progress: " << status.progress << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    std::cout << "progress: " << status.progress << std::endl;

    workerThread.join();
    return 0;
}

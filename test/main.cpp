#include <iostream>
#include <thread>
#include <chrono>
#include "workerhandler.h"

int main(int argc, char *argv[]) {
    WorkerHandler handler;

    handler.startOpenProject();
    while (handler.getStatus().isRunning) {
        std::cout << "openProject progress: " << handler.getStatus().progress << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "openProject progress: " << handler.getStatus().progress << std::endl;

    handler.startImportBigData();
    while (handler.getStatus().isRunning) {
        std::cout << "importBigData progress: " << handler.getStatus().progress << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "importBigData progress: " << handler.getStatus().progress << std::endl;

    handler.startProcessData();
    while (handler.getStatus().isRunning) {
        std::cout << "processData progress: " << handler.getStatus().progress << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "processData progress: " << handler.getStatus().progress << std::endl;

    handler.startSaveProject();
    while (handler.getStatus().isRunning) {
        std::cout << "saveProject progress: " << handler.getStatus().progress << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "saveProject progress: " << handler.getStatus().progress << std::endl;

    return 0;
}

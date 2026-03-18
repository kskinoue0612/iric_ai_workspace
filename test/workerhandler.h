#pragma once

#include <thread>
#include "worker.h"
#include "status.h"

class WorkerHandler {
public:
    WorkerHandler();
    ~WorkerHandler();

    void startOpenProject();
    void startSaveProject();
    void startImportBigData();
    void startProcessData();

    const Status& getStatus() const;

private:
    Worker m_worker;
    Status m_status;
    std::thread m_thread;
};

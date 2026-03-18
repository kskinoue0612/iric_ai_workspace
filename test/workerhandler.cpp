#include "workerhandler.h"

WorkerHandler::WorkerHandler() {}

WorkerHandler::~WorkerHandler() {
    if (m_thread.joinable()) {
        m_thread.join();
    }
}

void WorkerHandler::startOpenProject() {
    if (m_thread.joinable()) {
        m_thread.join();
    }
    m_status.isRunning = true;
    m_thread = std::thread([this]() {
        m_worker.openProject(m_status);
    });
}

void WorkerHandler::startSaveProject() {
    if (m_thread.joinable()) {
        m_thread.join();
    }
    m_status.isRunning = true;
    m_thread = std::thread([this]() {
        m_worker.saveProject(m_status);
    });
}

void WorkerHandler::startImportBigData() {
    if (m_thread.joinable()) {
        m_thread.join();
    }
    m_status.isRunning = true;
    m_thread = std::thread([this]() {
        m_worker.importBigData(m_status);
    });
}

void WorkerHandler::startProcessData() {
    if (m_thread.joinable()) {
        m_thread.join();
    }
    m_status.isRunning = true;
    m_thread = std::thread([this]() {
        m_worker.processData(m_status);
    });
}

const Status& WorkerHandler::getStatus() const {
    return m_status;
}

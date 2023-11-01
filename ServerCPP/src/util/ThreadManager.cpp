#include "util/ThreadManager.hpp"

ThreadManager::ThreadManager() {

}

ThreadManager::~ThreadManager() {

}

void ThreadManager::start() {
    for (auto& thread : this->threadList) {
        thread->start();
    }
}

void ThreadManager::join() {
    for (auto& thread : this->threadList) {
        thread->join();
    }
}

void ThreadManager::pushThread(Thread& thread) {
    this->threadList.push_back(&thread);
}
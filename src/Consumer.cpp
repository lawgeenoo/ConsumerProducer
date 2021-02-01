#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include "Consumer.h"

Consumer::Consumer() {
  m_thread = std::thread(&Consumer::process, this);

}

Consumer::~Consumer() {
  m_isRunning = false;
  cv.notify_one();
  if (m_thread.joinable()){
    m_thread.join();
  }
}

void Consumer::addEntry(int entry) {
  
  std::unique_lock<std::mutex> lk(m_mtx);
  m_dataQueue.push(entry);
  std::cout << "pushed " << entry << std::endl;
  cv.notify_one();

    
}
 

void Consumer::process() {
  
    while (m_isRunning) {
        std::unique_lock<std::mutex> lk(m_mtx);
        if (m_dataQueue.empty()) {
            cv.wait(lk);
    }

 
        else {
            std::cout << "popped " << m_dataQueue.front() << std::endl;
            m_dataQueue.pop();
        }
    }
}


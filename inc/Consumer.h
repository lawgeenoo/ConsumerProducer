 #ifndef CONSUMER_H
#define CONSUMER_H

#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

class Consumer {
 public:
    Consumer();
    ~Consumer();
    void addEntry(int entry);

 private:
    bool m_isRunning = true;
    std::condition_variable cv;
    std::mutex m_mtx;
    std::queue<int> m_dataQueue;
    std::thread m_thread;
    void process();
};

#endif  


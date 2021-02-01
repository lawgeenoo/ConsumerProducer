#include <random>
#include <thread>
#include <chrono>
#include "Consumer.h"

int main() {
  Consumer x;
  
  std::chrono::seconds sleep_time(1);

  std::random_device rd;
  std::mt19937 generate(rd());
  std::uniform_int_distribution<int> dist(1, 10);

  for (int i = 0; i < 10; i++) {
            int nbrOfEntries = dist(generate);

        for (int i = 0; i < nbrOfEntries; i++) {
            x.addEntry(i);
     }
  
     std::this_thread::sleep_for(sleep_time);
  }
  return 0;
}
 

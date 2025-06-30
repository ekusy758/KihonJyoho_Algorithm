#ifndef PRIO_QUEUE_H
#define PRIO_QUEUE_H

#include <queue>
#include <utility>
#include <string>

class PrioQueue {
  private:
    std::priority_queue<std::pair<int, std::string>> pq_;

  public:
    PrioQueue();

    void enqueue(std::string s, int prio);
    std::string dequeue();
    int size();
};

#endif
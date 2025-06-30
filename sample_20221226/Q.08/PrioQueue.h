#ifndef PRIO_QUEUE_H
#define PRIO_QUEUE_H

#include <queue>
#include <string>

struct OrderedQueueData {
  int prio;
  int order;
  std::string value;

  // Default descending to ascending!
  bool operator<(const OrderedQueueData& other) const {
    if (prio != other.prio) {
      return prio > other.prio;
    }
    return order > other.order;
  }
};

class PrioQueue {
  private:
    std::priority_queue<OrderedQueueData> pq_;
    int order_ = 0;

    void printQueue(); // For debug

  public:
    PrioQueue();

    void enqueue(std::string s, int prio);
    std::string dequeue();
    int size();
};

#endif
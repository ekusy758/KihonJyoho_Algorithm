#ifndef PRIO_QUEUE_H
#define PRIO_QUEUE_H

#include <queue>
#include <vector>
#include <string>

struct QueueEntry {
  int prio;
  int order;
  std::string value;
};

struct MinHeapCompare {
  bool operator()(const QueueEntry& a, const QueueEntry& b) const {
    if (a.prio != b.prio) {
      return a.prio > b.prio; // For Min-Heap
    }
    return a.order > b.order; // For FIFO order
  }
};

class PrioQueue {
  private:
    std::priority_queue<QueueEntry, std::vector<QueueEntry>, MinHeapCompare> pq_;
    int order_ = 0;

    void printQueue(); // For debug print

  public:
    PrioQueue();

    void enqueue(std::string s, int prio);
    std::string dequeue();
    int size();
};

#endif
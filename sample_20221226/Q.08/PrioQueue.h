#ifndef _PRIOQUEUE_H_
#define _PRIOQUEUE_H_
#include <set>
#include "queue_data.h"

using namespace std;

class PrioQueue {
private:
  void print_multiset();
public:
  multiset<queue_data> queue;
  PrioQueue();
  void enqueue(string s, int prio);
  queue_data dequeue();
  int size();
};

inline PrioQueue::PrioQueue() {
  queue.clear();
}

#endif

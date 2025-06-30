#include "PrioQueue.h"
#include <string>
#include <iostream>
#include <queue>

using namespace std;

PrioQueue::PrioQueue() {
  /* declared at private variable */
}

void PrioQueue::enqueue(string s, int prio) {
  pq_.push(OrderedQueueData{prio, order_++, s});
  cout << "enqueue: "; printQueue();
}

string PrioQueue::dequeue() {
  string val = pq_.top().value;
  pq_.pop();
  cout << "dequeue: "; printQueue();
  return val;
}

int PrioQueue::size() {
  return static_cast<int>(pq_.size());
}

// For debug
void PrioQueue::printQueue() {
  priority_queue<OrderedQueueData> copy = pq_;
  while (!copy.empty()) {
    OrderedQueueData item = copy.top();
    std::cout << "[" << item.value << ", " << item.prio << "(order:" << item.order << ")] ";
    copy.pop();
  }
  cout << endl;
}
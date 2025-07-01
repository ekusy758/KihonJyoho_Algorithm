#include "PrioQueue.h"
#include <string>
#include <iostream>
#include <queue>

using namespace std;

PrioQueue::PrioQueue() {
  /* Declared at private variable */
}

void PrioQueue::enqueue(string s, int prio) {
  pq_.push(QueueEntry{prio, order_++, s});
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
  auto copy = pq_;
  while (!copy.empty()) {
    QueueEntry qe = copy.top();
    std::cout << "[" << qe.value << ", " << qe.prio << "(order:" << qe.order << ")] ";
    copy.pop();
  }
  cout << endl;
}
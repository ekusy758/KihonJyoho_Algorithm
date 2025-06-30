#include "PrioQueue.h"
#include <queue>
#include <utility>
#include <vector>
#include <string>

PrioQueue::PrioQueue() {
  /* declared at private variable */
}

void PrioQueue::enqueue(std::string s, int prio) {
  pq_.emplace(-prio, s);
}

std::string PrioQueue::dequeue() {
  std::string s = pq_.top().second;
  pq_.pop();
  return s;
}

int PrioQueue::size() {
  return static_cast<int>(pq_.size());
}
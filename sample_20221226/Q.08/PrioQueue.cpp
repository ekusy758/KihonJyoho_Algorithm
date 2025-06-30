#include "PrioQueue.h"
#include <string>

using namespace std;

PrioQueue::PrioQueue() {
  /* declared at private variable */
}

void PrioQueue::enqueue(string s, int prio) {
  // Default is Descending, use '-' to invert!
  // (High) -1 > -2 > -3 > -4 (Low)
  pq_.emplace(-prio, s);
}

string PrioQueue::dequeue() {
  string s = pq_.top().second;
  pq_.pop();
  return s;
}

int PrioQueue::size() {
  return static_cast<int>(pq_.size());
}
#include "PrioQueue.h"
#include <iostream>

void PrioQueue::print_multiset() {
  cout << "    ƒLƒ…[ó‘Ô:";
  for (auto val : queue) {
    cout << " | " << val.s << ", " << val.prio;
  }
  cout << " | " << endl << endl;
}

void PrioQueue::enqueue(string s, int prio) {
  queue.insert(queue_data(s, prio));
  cout << "  Enqueue " << s << ", " << prio << endl;
  print_multiset();
}

queue_data PrioQueue::dequeue() {
  auto it = queue.begin();
  queue_data copy = *it;
  queue.erase(it);
  cout << "  Dequeue" << endl;
  print_multiset();
  return copy;
}

int PrioQueue::size() {
  return queue.size();
}

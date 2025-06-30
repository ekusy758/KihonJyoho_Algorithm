#include "PrioQueue.h"
#include <iostream>

void prioSched() {
  PrioQueue prioQueue;
  prioQueue.enqueue("A", 1);
  prioQueue.enqueue("B", 2);
  prioQueue.enqueue("C", 2);
  prioQueue.enqueue("D", 3);
  prioQueue.dequeue(); /* The return value is not used */
  prioQueue.dequeue(); /* The return value is not used */
  prioQueue.enqueue("D", 3);
  prioQueue.enqueue("B", 2);
  prioQueue.dequeue(); /* The return value is not used */
  prioQueue.dequeue(); /* The return value is not used */
  prioQueue.enqueue("C", 2);
  prioQueue.enqueue("A", 1);
  while (prioQueue.size() != 0) {
    std::cout << prioQueue.dequeue() << std::endl;
  }
}

int main() {
  prioSched();
  return 0;
}
#include <iostream>
#include "PrioQueue.h"

using namespace std;

void prioSched() {
  PrioQueue prioQueue;
  prioQueue.enqueue("A", 1);
  prioQueue.enqueue("B", 2);
  prioQueue.enqueue("C", 2);
  prioQueue.enqueue("D", 3);
  prioQueue.dequeue();
  prioQueue.dequeue();
  prioQueue.enqueue("D", 3);
  prioQueue.enqueue("B", 2);
  prioQueue.dequeue();
  prioQueue.dequeue();
  prioQueue.enqueue("C", 2);
  prioQueue.enqueue("A", 1);
  cout << "y–â‘è‚Ì‰ð“šz\n" << endl;
  while (prioQueue.size() != 0) {
    queue_data deq = prioQueue.dequeue();
    cout << "  Z–ß‚è’l: " << deq.s << "\n" << endl;
  }
}

int main() {
  prioSched();
  return 0;
}

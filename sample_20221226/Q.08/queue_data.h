#ifndef _QUEUE_DATA_H_
#define _QUEUE_DATA_H_
#include <string>

using namespace std;

class queue_data {
public:
  string s;
  int prio;
  queue_data(string s, int prio);
  friend bool operator<(const queue_data &qd1, const queue_data &qd2) {
    return qd1.prio < qd2.prio;
  }
};

inline queue_data::queue_data(string s, int prio) {
  this->s = s;
  this->prio = prio;
}

#endif

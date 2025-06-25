#include "ListElement.h"
#include <iostream>

using namespace std;

ListElement* listHead = nullptr;

void append(char qVal) {
  ListElement *prev, *curr;
  curr = new ListElement(qVal);
  if (listHead == nullptr) {
    listHead = curr;
  } else {
    prev = listHead;
    while (prev->next != nullptr) {
      prev = prev->next;
    }
    prev->next = curr;
  }
}

void printList(ListElement* head) {
  ListElement* curr = head;
  cout << "[Status]\n";
  while (curr != nullptr) {
    cout << "val: " << curr->val 
         << ", curr: " << curr
         << ", next: " << curr->next << "\n";
    curr = curr->next;
  }
  cout << endl;
}

void prompt() {
  char c;
  bool isBuf = false;
  cout << "Please [Ctrl+Z] Enter to end...\n";
  while (true) {
    if (!isBuf) cout << "Input a character: ";
    cin.get(c);
    if (cin.eof()) break;
    if (c == '\n') continue;
    append(c);
    if (cin.peek() == '\n') {
      isBuf = false;
      cin.get();
      printList(listHead);
    } else {
      isBuf = true;
    }
  }
}

int main() {
  prompt();
  return 0;
}
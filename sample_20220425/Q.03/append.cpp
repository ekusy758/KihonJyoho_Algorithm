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

int main(int argc, char** argv) {
  char c;
  cout << "Please [Ctrl+C] to End...\n";
  cout << "Type ASCII character and press Enter\n";
  while (true) {
    cin >> c;
    if (cin.eof()) {
      break; 
    }
    append(c);
    printList(listHead);
  }
  return 0;
}
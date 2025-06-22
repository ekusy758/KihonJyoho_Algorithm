#include "ListElement.h"
#include <iostream>

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
  std::cout << "[Status]\n";
  while (curr != nullptr) {
    std::cout << "val: " << curr->val 
              << ", curr: " << curr
              << ", next: " << curr->next << "\n";
    curr = curr->next;
  }
  std::cout << std::endl;
}

int main(int argc, char** argv) {
  char c;
  std::cout << "Please [Ctrl+C] to End...\n";
  std::cout << "Type ASCII character and press Enter\n";
  while (true) {
    std::cin >> c;
    if (std::cin.eof()) {
      break; 
    }
    append(c);
    printList(listHead);
  }
  return 0;
}
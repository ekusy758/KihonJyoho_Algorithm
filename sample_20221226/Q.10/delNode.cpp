#include "ListElement.h"
#include <iostream>

using namespace std;

void printList(ListElement* head);

ListElement* listHead = nullptr;

void delNode(int pos) {
  ListElement *prev;
  int i;
  if (pos == 1) {
    listHead = listHead->next;
  } else {
    prev = listHead;
    if (pos != 2) {
      for (i = 2; i <= pos - 1; i++) {
        if (prev->next == nullptr) return;
        prev = prev->next;
      }
    }
    if (prev->next == nullptr) return;
    prev->next = prev->next->next;
  }
  cout << "delNode: " << pos << "\n"; printList(listHead);
}

/* Same as the sample_20220425 Q3 */
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

/* Same as the sample_20220425 Q3 */
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

void presetNode() {
  append('R');
  append('O');
  append('U');
  append('T');
  append('E');
  append('6');
  append('6');
  cout << "appended: \n";
  printList(listHead);
}

int main() {
  presetNode();
  delNode(1); 
  delNode(2);
  delNode(4);
  delNode(3);
  delNode(1);
  delNode(1);
  delNode(1);
}
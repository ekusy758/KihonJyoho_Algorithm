#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

class ListElement {
  public:
    char val;
    ListElement *next;
    ListElement(char qVal) : val(qVal), next(nullptr) {}
    ListElement() : val('\0'), next(nullptr) {}
};

#endif
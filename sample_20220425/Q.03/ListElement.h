#ifndef LISTELEMENT_H
#define LISTELEMENT_H

class ListElement {
  public:
    char val;
    ListElement *next;
    ListElement(char qVal) : val(qVal), next(nullptr) {}
    ListElement() : val('\0'), next(nullptr) {}
};

#endif
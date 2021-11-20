#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class LinkedList
{
public:
    LinkedList();
    int size();
    void insert(int _data);
    void deletee(int _data);
    bool search(int _data);
    void showList() const;
private:
    Node* firstNode;
};

#endif // LINKEDLIST_H

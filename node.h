#ifndef NODE_H
#define NODE_H

#include<iostream>


class Node{
public:
    Node();
    Node(int _data);
    int data;
    Node* nextNode;
    ~Node();


};

#endif // NODE_H

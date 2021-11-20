#include "node.h"

Node::Node()
{
    this->data=NULL;
    this->nextNode=NULL;

}
Node::Node(int _data): data{_data}, nextNode{NULL}{
}



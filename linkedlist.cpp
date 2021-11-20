#include "linkedlist.h"
#include "node.h"

#include <QDebug>
LinkedList::LinkedList()
{
    this->firstNode=NULL;
}
void LinkedList::insert(int _data){
    Node* newNode= new Node(_data);

    if(this->firstNode==NULL){
        this->firstNode= newNode;
    }
    else{
        Node* iterator= this->firstNode;//nodo iterador
        while(iterator->nextNode!=NULL){//recorrer hasta buscar un nodo vacio
            iterator=iterator->nextNode;
        }
        iterator->nextNode= newNode;
    }
}

int LinkedList:: size(){
   Node* iterator= this->firstNode;
   int size=0;
   if(this->firstNode==NULL)
       return 0;
   else{
       while(iterator!=NULL){
           iterator=iterator->nextNode;
           size++;
       }
        return size;
   }
}

void LinkedList::deletee(int index)
{
    Node *aux1 = this->firstNode;
    Node *aux2 = NULL;
    int size =this->size();
    // Comprueba si la lista esta vacia
    if (this->firstNode == NULL) {
        qDebug() << "Lista vacia.";
        return;
    }

    if (size < index) {
        qDebug() << "No se elimino: "<<index;
        return;
    }
    qDebug() << "Eliminando: "<<index;
    if (index == 1) {// si el nodo es el primero
        // Actualizar cabecera
        this->firstNode = this->firstNode->nextNode;
        delete aux1;
        return;
    }
    // Recorre la lista para
    // buscar el Nodo que se va a eliminar.
    while (index-- > 1) {
        // Actualizar aux2
        aux2 = aux1;
        // Actualizar aux1
        aux1 = aux1->nextNode;
    }
    // Cambiar el siguiente puntero
    // del Nodo anterior.
    aux2->nextNode = aux1->nextNode;
    // Eliminar nodo
    delete aux1;
}

bool LinkedList::search(int _data){
    Node* iterator= this->firstNode;
    if(this->firstNode){
        return false;
    }
    else{
        while(iterator!=NULL){
            if(iterator->data==_data){
                return true;
                break;
            }
            iterator=iterator->nextNode;
        }
    }
    return false;
}

void LinkedList::showList() const{
    Node* iterator= this->firstNode;
    if(this->firstNode==NULL)
        qDebug()<<"Lista vacia\n";
    else{
        while(iterator!=NULL){
         qDebug()<<iterator->data<<", ";
         iterator=iterator->nextNode;
        }
    }
}

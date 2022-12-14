#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

#include "ListNode.h"

template<typename T>
class List //linked list of ListNode objects
{
public:
    List();
    ~List();

    void print() const; //prints the contents of the linked list
    ListNode<T>* search(T); //searches for a value in the linked list and returns the point to object that contains that value
    void insertEnd(T); //inserts new node after the last node in the list
    void removeNode(T);

    ListNode<T>* startPtr; //stores the pointer of first object in the linked list
    ListNode<T>* endPtr; //stored the pointer of the last object in the linked list
    bool isEmpty() const; //utility functions used to see if the list contains no elements


};


template<typename T>
List<T>::List() //creates list with start and end as NULL
{
    startPtr = NULL;
    endPtr = NULL;
}

template<typename T>
List<T>::~List() {
    if (!isEmpty()) // List is not empty
    {
        ListNode<T>* currentPtr = startPtr;
        ListNode<T>* tempPtr;

        while (currentPtr != 0) // delete remaining nodes
        {
            tempPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }
}

template<typename T>
bool List<T>::isEmpty() const {
    if (startPtr == NULL && endPtr == NULL) //if the start pointer and end pointer are NULL then the list is empty
        return 1;
    else
        return 0;
}

template<typename T>
void List<T>::removeNode(T dataIn) {
    ListNode<T>* nodeToRemove = search(dataIn);

    if (nodeToRemove->data == startPtr->data) {
        startPtr = nodeToRemove->nextPtr;
    }
    else {
        ListNode<T>* previousNode = startPtr;
        while (previousNode->nextPtr != nullptr) {
            if (previousNode->nextPtr->data == dataIn) {
                break;
            }
            previousNode = previousNode->nextPtr;
        }
        if (nodeToRemove->data == endPtr->data) {
            endPtr = previousNode;
            endPtr->nextPtr = nullptr;

        }
        else {
            previousNode->nextPtr = nodeToRemove->nextPtr;
        }
    }
}

template<typename T>
void List<T>::insertEnd(T dataIn) {
    if (isEmpty()) //if the list is empty create first element of the list (same as first case in insert at begin)
    {
        ListNode<T>* newPtr = new ListNode<T>(dataIn);
        startPtr = newPtr;
        endPtr = newPtr;
    }
    else //if node(s) exist in the list then insert new node at the end of the list
    {
        ListNode<T>* newPtr = new ListNode<T>(dataIn);
        endPtr->nextPtr = newPtr; //the current last node's next pointer points to the new node
        endPtr = newPtr; //the new node is now the last node in the list
    }
}


template<typename T>
void List<T>::print() const {
    if (isEmpty()) {
        cout << "The list is empty" << endl;

    }
    else {
        ListNode<T>* currentPtr = startPtr;

        cout << "The contents of the list is: \n";
        while (currentPtr != NULL) //prints until the end of the list is reached
        {
            cout << currentPtr->data;
            currentPtr = currentPtr->nextPtr; //moves to next node in list
        }
        cout << endl;
    }
}

template<typename T>
ListNode<T>* List<T>::search(T key) //search functions that searches for node that contains data equal to the key
{
    ListNode<T>* nodePtr;
    bool found = false;

    nodePtr = startPtr;

    while ((!found) &&
        (nodePtr != NULL)) //runs through list until data is found within a node or end of list is reached
    {
        if (nodePtr->data == key) //if the node's data equals the key then the node has been found
            found = true;
        else
            nodePtr = nodePtr->nextPtr; //moves to next node in list
    }
    return nodePtr; //returns pointer to the node that contains data equal to key (NULL if not found)
}

#endif
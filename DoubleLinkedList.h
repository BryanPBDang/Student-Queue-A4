/*
 Bryan Dang
 Student ID: 2295344
 Email: bdang@chapman.edu
 Class: CPSC 350
 Section: 1
 Assignment 4: Register Office Simulation
 Purpose: DoublyLinkedList
 */

#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H

#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class DoublyLinkedList
{
  public:
    DoublyLinkedList(); //Constructor
    ~DoublyLinkedList(); //Destructor

    unsigned int size;
    ListNode<T> *front;
    ListNode<T> *back;

    void insertBack(T data);
    T removeFront();
    ListNode<T>* getFront();

    void printList();
    void deletePos(int pos);

    bool isEmpty();
    unsigned int getSize();
};

//CONSTRUCTOR
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{

}

//insert back
template <class T>
void DoublyLinkedList<T>::insertBack(T data)
{
  ListNode<T> *node = new ListNode<T>(data);

   if(size == 0)
   {
       front = node;
   }

   else
   {
       back->next = node;
       node->prev = back;
   }
   back = node;
   ++size;
}


//remove front
template <class T>
T DoublyLinkedList<T>::removeFront()
{
  if(!isEmpty())
  {
    ListNode<T> *node = front;

//empty Check
    if(front->next == NULL)
    {
      front = NULL;
      back = NULL;
    }
    else
    {
      front->next->prev = NULL;
      front = front->next;
    }
//move node then delete
    T temp = node->data;
    delete node;
    size;
    return temp;
  }
  else
  {
    return T();
  }
}

//print front value
template <class T>
ListNode<T>* DoublyLinkedList<T>::getFront()
{
  return front;
}

//print whole list
template <class T>
void DoublyLinkedList<T>::printList()
{
  ListNode<T> *curr = front;
  while(true){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

//delete value
template <class T>
void DoublyLinkedList<T>::deletePos(int pos) {
  int idx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

   while(idx != pos)
    {
     prev = curr;
     curr = curr->next;
     idx++;
   }
//moving nodes
   prev->next = curr->next;
   curr->next->prev = prev;
   curr->next = NULL;

   size--;
   delete curr;
}

//empty DLL
template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return(size == 0);
}

//return the size of DLL
template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}
#endif

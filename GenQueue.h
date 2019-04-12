/*
 Bryan Dang
 Student ID: 2295344
 Email: bdang@chapman.edu
 Class: CPSC 350
 Section: 1
 Assignment 4: Register Office Simulation
 Purpose: Queue that works with a double linked list
 */

 #ifndef GenQueue_H
 #define GenQueue_H

#include "GenQueue.h"
#include <iostream>

#include "DoublyLinkedList.h"
#include "ListNode.h"

using namespace std;

//TEMPLATE CLASS
template <class T>
class GenQueue
{
  public:
    unsigned int numElements;
    ListNode<T> *front;
    ListNode<T> *back;

    GenQueue();
    ~GenQueue();

    void enqueue(T d);
    T dequeue();

    T vFront();
    T vBack();

    void printQ();
    bool isEmpty();
    unsigned int getSize();
};

//DEFAULT CONSTRUCTOR
template <class T>
GenQueue<T>::GenQueue()
{
  numElements = 0;
  front = NULL;
  back = NULL;
}


/*

GenQueue :: GenQueue(int maxSize) //Overloaded constructor
{
  myQueue = new char[maxSize];
  mSize = maxSize;
  head = 0;
  tail = -1;
  numElements = 0;
}

*/

// deconstructor
template <class T>
GenQueue<T>::~GenQueue()
{

}

//Insert/enqueue
template <class T>
void GenQueue<T>::enqueue(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  if(numElements == 0) {
      front = node;
  }
  else {
      back->next = node;
      node->prev = back;
  }

  back = node;
  ++numElements;
}




//Remove/Dequeue
template <class T>
T GenQueue<T>::dequeue() {


  if(!isEmpty()) {
    ListNode<T> *node = front;

    T temp = node->data;

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

    delete node;
    numElements--;
    return temp;
  }
  else
  {
    return T();
  }
}

//Peek/Front
template <class T>
T GenQueue<T>::vFront()
{
  if(isEmpty() == false)
  {
    return front->data;
  }
  return T();
}

//Peek/Back
template <class T>
T GenQueue<T>::vBack()
{
  if(isEmpty() == false)
  {
    return back->data;
  }
  return T();
}

//print out queue
template <class T>
void GenQueue<T>::printQ()
{
  ListNode<T> *curr = front;
//moving nodes
    while(true)
    {
        if(curr != NULL)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }
        else
        {
            break;
        }
    }
}

//If Queue is empty
template <class T>
bool GenQueue<T>::isEmpty()
{
  return (numElements == 0);
}

//return queue size
template <class T>
unsigned int GenQueue<T>::getSize()
{
  return numElements;
}
#endif

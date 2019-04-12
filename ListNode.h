
/*
 Bryan Dang
 Student ID: 2295344
 Email: bdang@chapman.edu
 Class: CPSC 350
 Section: 1
 Assignment 4: Register Office Simulation
 Purpose: ListNode Class
 */
#ifndef ListNode_H
#define ListNode_H
#include <iostream>
using namespace std;

//constructor
template <class T>
class ListNode
{
  public:
    ListNode();
    ListNode(T d);
    ~ListNode();

    T data;
    ListNode<T> *next;
    ListNode<T> *prev;
};


template<class T>
ListNode<T>::ListNode()
{

}

//default constructor
template<class T>
ListNode<T>::ListNode(T d)
{
  next = NULL;
  prev = NULL;
  data = d;
}

//deconstructor
template<class T>
ListNode<T>::~ListNode()
{
  next = NULL;
  prev = NULL;
}
#endif

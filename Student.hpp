/*
 Bryan Dang
 Student ID: 2295344
 Email: bdang@chapman.edu
 Class: CPSC 350
 Section: 1
 Assignment 4: Register Office Simulation
 Purpose: Student class header
 */


#include <iostream>
using namespace std;

class Student
{
  public:
    //methods
    Student();
    Student(int needs, int arrived);

    //variables
    int timeNeeded;
    int timeSpent;
    int timeWaited;
    int arrivalTime;
};

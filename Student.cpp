/*
 Bryan Dang
 Student ID: 2295344
 Email: bdang@chapman.edu
 Class: CPSC 350
 Section: 1
 Assignment 4: Register Office Simulation
 Purpose: Student class to hold queue variables
 */
 #include <iostream>
 #include "Student.hpp"

 using namespace std;
//constructor
 Student::Student()
 {
   timeNeeded = 0;
   timeSpent = 0;
   timeWaited = 0;
   arrivalTime = 0;
 }
//constructor - need/arrival
 Student::Student(int timeN, int timeA)
 {
   timeNeeded = needs;
   arrivalTime = arrived;
   timeSpent = 0;
   timeWaited = 0;
 }

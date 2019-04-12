/*
 Bryan Dang
 Student ID: 2295344
 Email: bdang@chapman.edu
 Class: CPSC 350
 Section: 1
 Assignment 4: Register Office Simulation
 Purpose: Driver to perform assignment
 */


#include <iostream>
#include <fstream>
#include "GenQueue.h"
#include "Implmentation.hpp"


int main(int argc, char** argv)
{
  string fileName;

  // CANT ADD ARGUMENTS IN HERE,STOI ERROR :(
  fileName = argv[1];

  Implmentation i(fileName);
  i.move();

/*
The mean student wait time.
2.The median student wait time.
3.The longest student wait time
.4.The number of students waiting over 10 minutes5.
The mean window idle time
6.The longest window idle time
7.Number of windows idle for over 5 minutes

*/
  cout << "The mean student wait time is: " << i.meanWait << endl;
  cout << "The median student wait time is: " << i.medianWait << endl;
  cout << "The longest student wait time is: " << i.longWait << endl;
  cout << "The number of students waiting over 10 minutes is: "<< i.tenPlus << endl;
  cout << "The mean window idle time is:  " << i.meanIdle << endl;
  cout << "The longest window idle time is: " << i.longestIdle << endl;
  cout << "Number of windows idle for over 5 minutes: "<< i.fivePlus << endl;



}

/*
 Bryan Dang
 Student ID: 2295344
 Email: bdang@chapman.edu
 Class: CPSC 350
 Section: 1
 Assignment 4: Register Office Simulation
 Purpose: Implmentation Class
 */

#include <iostream>
#include <fstream>
#include "Implmentation.hpp"
#include "GenQueue.h"
#include <algorithm>

using namespace std;

//constructor
Implmentation::Implmentation()
{
  numberPeople = 0;
  timer = 0;
  meanWait = 0;
  medianWait = 0;
  longWait = 0;
  meanIdle = 0;
  longestIdle = 0;
  tenPlus = 0;
  fivePlus = 0;
}

//constructor that takes file parameter
Implmentation::Implmentation(string file)
{
  arrv = 0;
  counter = 0;
  fileName = file; //sets fileName
  longWait = 0;
  longestIdle = 0;
  meanWait = 0;
  medianWait = 0;
  meanIdle = 0;
  numberPeople = 0;
  timer = 0;
  total = 0;
  tenPlus = 0;
  fivePlus = 0;
  calculate();
}

//  Goes through wait array, if there is more than 5 -> count
double Implmentation::overFive()
{
  for(int j = 0; j < windowAmount; j++)
  {
    if(idleArray[j] > 5)
    {
      fivePlus++;
    }
  }
}

//  Goes through wait array, if there is more than 10 -> count
double Implmentation::overTen()
{
  for(int i = 0; i < total; i++)
  {
    if(waitArray[i] > 10)
    {
      tenPlus++;
    }
  }
}


//  Goes through wait array to find the longest idle person
double Implmentation::longestWait()
{
  for(int i = 0; i < total; i++)
  {
    if(longWait < waitArray[i])
    {
      longWait = waitArray[i];
    }
  }
}

//  Goes through idle array to find the longest idle person
double Implmentation::longestIdleWait()
{
  for(int j = 0; j < windowAmount; j++)
  {
    if(longestIdle < idleArray[j])
    {
      longestIdle = idleArray[j];
    }
  }
}


//check if windows are empty
bool Implmentation::windowsAreEmpty()
{
//iterate
  for(int i = 0; i < windowAmount; i++)
  {
    //if there is something in windows, return false cause it is not empty
    if(windows[i] == true)
    {
      return false;
    }
  }
  return true;
}

//Check number of people in windows
int Implmentation::checkWindows()
{
  //iterate
  for(int i = 0; i < windowAmount; i++)
  {
    //return i
    if(windows[i] == false)
    {
      return i;
    }
  }
  return -1;
}

// Sorting then find median
double Implmentation::median()
{
  sort(waitArray, waitArray + total - 1);
  if((total % 2) == 1)
  {
    return waitArray[(total/2)];
  }
  else
  {
    return ((waitArray[total/2]+waitArray[(total/2)-1]));
  }
}

void Implmentation::calculate()
{
  //Read file and new instances
  inFile.open(fileName);
  inFile >> currentLine;
  windowAmount = stoi(currentLine);
  personAtWindow = new Student[windowAmount];
  windows = new bool[windowAmount];
  idleArray = new int[windowAmount];
  int peopleArriving;
 //Iterates , assigning variables in order
  while(!inFile.eof())
  {
    inFile >> currentLine;
    arrv = stoi(currentLine);

    inFile >> currentLine;
    peopleArriving = stoi(currentLine);

    for(int i = 0; i < peopleArriving; i++)
    {
      //add each student and the correspodning time
      inFile >> currentLine;
      Student p(stoi(currentLine), arrv);
      total++;
      begin.enqueue(p);
    }
  }
  waitArray = new int[total];
}

//clear windows, then add new based on time spend and time needed
void Implmentation::clearWindows()
{
  //iterate

  for(int i = 0; i < windowAmount; i++)
  {
    if(windows[i] == true)
    {
      if (personAtWindow[i].timeSpent == personAtWindow[i].timeNeeded)
      {
        windows[i] = false;
        Student temp = personAtWindow[i];
        if(temp.timeWaited == 0)
        {
          waitArray[numberPeople] = 0;
        }
        else
        {
          waitArray[numberPeople] =  temp.timeWaited - 1;
        }
        numberPeople++; //increments the number of people
      }
    }
  }
}

//add Student to Queue
void Implmentation::add()
{
  Student p = begin.vFront();
  while(p.arrivalTime == timer)
  {
    end.enqueue(p);
    begin.dequeue();
    p = begin.vFront();
  }
}

//move idle student to window
void Implmentation::move()
{
  //check empty
    while(!begin.isEmpty()|| !end.isEmpty() || !windowsAreEmpty())
    {
      if(!begin.isEmpty())
      {
        add();
      }

      clearWindows();

      while(checkWindows() != -1 && !end.isEmpty())
      {
        Student temp = end.vFront();
        int openWindow = checkWindows();
        windows[openWindow] = true;
        personAtWindow[openWindow] = temp;
        end.dequeue();
      }

      for(int i = 0; i < windowAmount; i++)
      {
        personAtWindow[i].timeSpent++;
      }

      GenQueue<Student> copy;
      while(!end.isEmpty())
      {
        Student temp1 = end.vFront();
        end.dequeue();
        copy.enqueue(temp1);
      }

      while(!copy.isEmpty())
      {
        Student temp = copy.vFront();
        copy.dequeue();
        temp.timeWaited++;
        end.enqueue(temp);
      }

      for(int i = 0; i < windowAmount; i++)
      {
        if(windows[i] == false)
        {
          idleArray[i]++;
        }
      }

      if(timer == 5)
      {
        Student test = end.vFront();
      }
      timer++;
    }

  //summary of results
    longestWait();

    overTen();

    longestIdleWait();

    overFive();

    for(int j = 0; j < windowAmount; j++)
    {
      meanIdle = meanIdle + idleArray[j];
    }

    for(int i = 0; i < total; i++)
    {
      meanWait = meanWait + waitArray[i];
    }

    meanWait = meanWait/total;
    medianWait = median();
    meanIdle = meanIdle/windowAmount;
}

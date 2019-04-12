#include <iostream>
#include "Student.hpp"
#include "GenQueue.h"

using namespace std;

class Implmentation
{
  public:
    Implmentation();
    Implmentation(string fileName);


    int total; // total amount of people exsisted
    int numberPeople; // number of people currently there
    int windowAmount; // amount of windows
    int timer; //flow of time for customers
    int counter; // counter variable
    int arrv; // counter varible
    int medianWait; //median of the waiting times
    int longWait; //longest wait time
    int tenPlus; //wainting for 10
    int fivePlus; //waiting for 5

    string fileName; // file name
    string currentLine; // iterates through file

    int *idleArray; // array of idle students
    int *waitArray; //array of waiting students
    bool *windows; //which windows are open
    Student *personAtWindow; //the student at the window

    double meanWait; //average wait time
    double meanIdle; //average idle time
    double longestIdle; //longest idle time


    ifstream inFile; //file stream

    GenQueue<Student> begin; //Start student queue
    GenQueue<Student> end; //students in the queue

    double longestWait();
    double overTen();
    double overFive();
    double longestIdleWait();
    double median();


    void calculate();
    void add();
    void move();
    void clearWindows();

    bool windowsAreEmpty();
    int checkWindows();
    int windowsOpen();

};

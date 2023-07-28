#ifndef _PQSORT_H
#define _PQSORT_H
#include <iostream>
#include <list>
#include <cmath>
using namespace std;

struct Elem {
    int prio;
    int value;
};

  class PriorityQueue {                 // priority-queue interface
  public:
    PriorityQueue(); // constructor
    int size();                 // number of elements
    bool isEmpty();             // is the queue empty?
    void insert(int v);             // insert element
    const int min();        // minimum element
    void removeMin();   // remove minimum
    void iterate(int len);
private:
      std::list<int> L;
      int n; // size
};

#endif

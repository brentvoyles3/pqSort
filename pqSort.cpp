#include <iostream>
#include "pqSort.h"

using namespace std;

//fn prototype
void isPhase2(int * elements, PriorityQueue q, int size);

/*
 * Priority Queue constructor, initialize size. List already initialized.
 */
PriorityQueue::PriorityQueue() {
    n = L.size();
}

/*
 * Returns the number of elements in the priority queue.
 */
int PriorityQueue::size () {
    return n;
}

/*
 * Returns true if the pq isempty, false otherwise.
 */
bool PriorityQueue::isEmpty() {
    return n == 0;
}

/*
 * Iterate over elements in a priority queue
 */
void PriorityQueue::iterate(int len) {
    list<int>::iterator p;
    p = L.begin();
    auto it = L.begin();
    while (p != L.end()) {
        auto nxt = std::next(it, 1);
        cout << *it << ",";
        it = nxt;
        ++p;
    }
}

/*
 * Insert integer value to priority queue
 */
void PriorityQueue::insert(int val) {
    std::list<int>::iterator it;
    it = L.begin();
    while (it != L.end() && !isless(val, *it)) {
        ++it;
    }
    //insert at sorted location
    L.insert(it, val);
    //increase size
    n++;
}

/*
 * Removes the first element from sorted pq, the minimum.
 */
void PriorityQueue::removeMin() {
    n--;
    L.pop_front();
}

/*
 * Returns the minimum element in a list
 */
const int PriorityQueue::min() {
    return L.front();
}

/*
 * Insertion Sort phase 1, copy sorted elements to priority queue.
 */
void isPhase1(int * sequence, int size) {
    cout << "Phase One:" << endl;
    cout << "Sequence    Priority Queue" << endl;
    PriorityQueue pq;
    int j = 1;
    for (int idx = 0; idx < size; idx++) {
        for (int i = j; i < size; i++) {
            cout << sequence[i] << ",";
        }
        if (j == size) {
            cout << "-";
        }
        pq.insert(sequence[idx]);
        cout << "           ";
        pq.iterate(j);
        cout << "\n";
        j++;
    } // outer for
    isPhase2(sequence, pq, size);
} // isPhase1

/*
 * Insertion Sort phase 2, add sorted elements back to sequence.
 */
void isPhase2(int * elements, PriorityQueue q, int size) {
    cout << "Phase Two:" << endl;
    cout << "Sequence    Priority Queue" << endl;
    int sequence[size];
    PriorityQueue pq2;
    //pop pq elements off to list in order
    for (int i = 0; i < size; i++) {
        sequence[i] = q.min();
        pq2.insert(sequence[i]);
        q.removeMin();
    }
    int idx  = 0, j =1;
    for (int k = 0; k < size; k++) {
        for (int p = 0; p <= idx ; p++) {
            if (p == idx) {
                cout << sequence[p];
            } else {
                cout << sequence[p] << ",";
            }
        }
        cout << "          ";
        pq2.removeMin();
        pq2.iterate(size);
        idx++;
        j++;
        if (idx == size) {
            cout << "-";
        }
        cout << "\n";
    }
} //isPhase2

/*
 * Selection Sort Phase 2, add unsorted elements in pq to sequence
 */
void ssPhase2(int * elements, PriorityQueue q, int size) {
    cout << "Phase Two:" << endl;
    cout << "Sequence    Priority Queue" << endl;
    int sequence[size];
    list<int> temp;
    //pop pq elements off to list in order
    for (int i = 0; i < size; i++) {
        temp.push_back(elements[i]);
        sequence[i] = q.min();
        q.removeMin();
    }
    int idx  = 0, j = 1;
    for (int k = 0; k < size; k++) {
        for (int p = 0; p <= idx ; p++) {
            if (p == idx) {
                cout << sequence[p];
            } else {
                cout << sequence[p] << ",";
            }
        }
        cout << "          ";
        temp.remove(sequence[idx]);
        list<int>::const_iterator iterator;
        for (iterator = temp.begin(); iterator != temp.end(); ++iterator) {
            cout << *iterator << ",";
        }
        idx++;
        j++;
        if (idx == size) {
            cout << "-";
        }
        cout << "\n";
    } // for
} // ssPhase2

/*
 * Selection sort phase 1. Insert input items to priority queue.
 */
void ssPhase1(int * elements, int size) {
    PriorityQueue myList;
    cout << "Phase One:" << endl;
    cout << "Sequence    Priority Queue" << endl;
    int idx  = 0;
    int j = 1;
    for (int k = 0; k < size; k++) {
        for (int i = j;i < size ; i++) {
            cout << elements[i] << ",";
        }
        if (j == size) {
            cout << "-";
        }
        cout << "          ";
        myList.insert(elements[idx]);
        for (int p = 0; p <= idx; p++) {
            cout << elements[p] << ",";
        }
        idx++;
        j++;
        cout << "\n";
    }
    ssPhase2(elements, myList, size);
} // ssPhase1

/*
 * Main function for handling input and calling sort functions.
 */
int main() {
    string whichSort;
    int numElements;
    cout << "Selection Sort or Insertion Sort? (Enter S or I)" << endl;
    cin >> whichSort;
    cout << "Enter the number of elements:" << endl;
    cin >> numElements;
    int sequence[numElements];
    cout << "Enter each element separated line by line: \n";
    for (int i = 0; i < numElements; i++) {
        cin >> sequence[i];
            }
    if ((whichSort[0] == 's') || (whichSort[0] == 'S')) {
         ssPhase1(sequence, numElements);
    } else {
        isPhase1(sequence, numElements);
    }
    return 0;
} // main

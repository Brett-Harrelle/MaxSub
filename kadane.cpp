//file  :  kadane.cpp
//author:  Brett Harrelle
//desc. :  implementation of kadane's linear time max sub array algorithm.
#include <iostream>


using namespace std;

const char* kadSortAuthor = "Brett Harrelle";

//A[] is an array of deltas.
void kadane(int A[], int N, int& bestStart, int& bestEnd, int& bestSum) {

    int meh = A[0];  //max ending here
    int currentStart = 0;
    bestStart = 0;
    bestEnd = 0;
    bestSum = A[0];  //max so far

    for (int i = 1; i < N; i++) {
        meh = max(A[i], meh + A[i]);
        if (meh == A[i]) {
            currentStart = i;
        }
        if (meh > bestSum) {
            bestSum = meh;
            bestStart = currentStart;
            bestEnd = i;
        }
    }
}
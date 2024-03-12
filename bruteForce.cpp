// file  : bruteForce.cpp
// author: Brett Harrelle
// desc. : this file contains brute force implementations for the max sub
//         array problem in N^2.
//

#include <iostream>
#include <limits.h>
using namespace std;

const char* bruAuthor = "Brett Harrelle";
//---------------------------------------------------------------------------
//A[] is an array of deltas.
void bruteForce_n2(int A[], int N, int& bestStart, int& bestEnd, int& bestSum) {

    bestSum = INT_MIN;                          //O(1)
    
    for (int i = 0; i < N; i++) {               //N times
        int currentSum = 0;                     //O(1)
        for (int j = i; j < N; j++) {           //N - i
            currentSum += A[j];                 //O(1)
            if (currentSum > bestSum) {         //O(1)
                bestSum = currentSum;           //O(1)
                bestStart = i;                  //O(1)
                bestEnd = j;                    //O(1)
            }
        }
    }
}                                               //overall sum of N, N-1, N-2,...,1    this equals N(N+1)/2   which is O(N^2)
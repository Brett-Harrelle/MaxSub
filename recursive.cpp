// file  : recursive.cpp
// author: Brett Harrelle
// desc. : this file contains the entry point (and helper functions) for 
//         the recursive max subarray problem/solution.
#include <iostream>
#include <limits.h>

using namespace std;

const char* recAuthor = "Brett Harrelle";

//(insert helper function(s) here, if any.they should all be static.)

static void find_maximum_crossing_subarray(int A[], int low, int mid, int high, int& bestStart, int& bestEnd, int& bestSum) {
    //best for left starting at mid moving left
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > leftSum) {
            leftSum = sum;
            bestStart = i;
        }
    }
    //best for right starting at mid + 1 moving right
    int rightSum = INT_MIN;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += A[j];
        if (sum > rightSum) {
            rightSum = sum;
            bestEnd = j;
        }
    }
    bestSum = leftSum + rightSum;
}

static void find_maximum_subarray(int A[], int low, int high, int& bestStart, int& bestEnd, int& bestSum) {
    //best case
    if (high == low) {
        bestStart = low;
        bestEnd = high;
        bestSum = A[low];
    }
    else {
        int mid = (low + high) / 2;
        //find max in left sub half
        int leftStart, leftEnd, leftSum;
        find_maximum_subarray(A, low, mid, leftStart, leftEnd, leftSum);
        //find max in right sub half
        int rightStart, rightEnd, rightSum;
        find_maximum_subarray(A, mid + 1, high, rightStart, rightEnd, rightSum);
        //crossing max
        int crossStart, crossEnd, crossSum;
        find_maximum_crossing_subarray(A, low, mid, high, crossStart, crossEnd, crossSum);
        //return max
        if (leftSum >= rightSum && leftSum >= crossSum) {
            bestStart = leftStart;
            bestEnd = leftEnd;
            bestSum = leftSum;
        }
        else if (rightSum >= leftSum && rightSum >= crossSum) {
            bestStart = rightStart;
            bestEnd = rightEnd;
            bestSum = rightSum;
        }
        else {
            bestStart = crossStart;
            bestEnd = crossEnd;
            bestSum = crossSum;
        }
    }
}

//A[] is an array of deltas.

void find_maximum_subarray(int A[], int N, int& bestStart, int& bestEnd, int& bestSum) {
    find_maximum_subarray(A, 0, N - 1, bestStart, bestEnd, bestSum);
}
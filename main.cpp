// file  : main.cpp
// author: Brett Harrelle
// desc. : this file contains code that exercises the functions:
//         bruteForce_n2, find_maximum_subarray, and kadane.
//
#include <iostream> 
#include <stdlib.h> 
#include <random>
#include <Windows.h>
#include <cmath>

extern void bruteForce_n2(int A[], int N, int& bestStart, int& bestEnd, int& bestSum);
extern void find_maximum_subarray(int A[], int N, int& bestStart, int& bestEnd, int& bestSum);
//to make things simpler for kadane:
extern void kadane(int A[], int N, int& bestStart, int& bestEnd, int& bestSum);

using namespace std;

static mt19937_64 gen((unsigned int)time(NULL));

static double cpuTime(void) {

    FILETIME  createTime;
    FILETIME  exitTime;
    FILETIME  kernelTime;
    FILETIME  userTime;

    if (GetProcessTimes(GetCurrentProcess(), &createTime, &exitTime, &kernelTime, &userTime) != -1) {
        SYSTEMTIME  userSystemTime;
        if (FileTimeToSystemTime(&userTime, &userSystemTime) != -1)
            return (double)userSystemTime.wHour * 3600.0 +
            (double)userSystemTime.wMinute * 60.0 +
            (double)userSystemTime.wSecond +
            (double)userSystemTime.wMilliseconds / 1000.0;
    }
    return -1;
}

int main(int argc, char* argv[]) {

    uniform_int_distribution<> distrib(-100, 100);

    const int arraySize = 100;
    int testArray[arraySize];

    for (int i = 0; i < arraySize; i++) {
        testArray[i] = distrib(gen);
        //cout << testArray[i] << endl;  // if you want to see numbers distributed
    }
    
    int bruteStart, bruteEnd, bruteSum;
    int recursiveStart, recursiveEnd, recursiveSum;
    int kadaneStart, kadaneEnd, kadaneSum;

    //mark start time Brute Force
    clock_t  stB = clock();
    double  startB = cpuTime();
    //Test Brute Force
    bruteForce_n2(testArray, arraySize, bruteStart, bruteEnd, bruteSum);
    //mark end time Brute Force
    double  endB = cpuTime();
    clock_t  etB = clock();

    //mark start time Max Sub
    clock_t  stM = clock();
    double  startM = cpuTime();
    //Test recursive solution
    find_maximum_subarray(testArray, arraySize, recursiveStart, recursiveEnd, recursiveSum);
    //mark end time Max Sub
    double  endM = cpuTime();
    clock_t  etM = clock();

    //mark start time Kadane
    clock_t  stK = clock();
    double  startK = cpuTime();
    //Test Kadane's algorithm
    kadane(testArray, arraySize, kadaneStart, kadaneEnd, kadaneSum);
    //mark end time Kadane
    double  endK = cpuTime();
    clock_t  etK = clock();

    //calc deltas Brute Force
    double  cpuTimeB = endB - startB;
    double  elapsedTimeB = ((double)etB - stB) / CLOCKS_PER_SEC;

    //calc deltas Max-sub
    double  cpuTimeM = endM - startM;
    double  elapsedTimeM = ((double)etM - stM) / CLOCKS_PER_SEC;

    //calc deltas Kadane
    double  cpuTimeK = endK - startK;
    double  elapsedTimeK = ((double)etK - stK) / CLOCKS_PER_SEC;

    //show results of Brute Force
    cout << "Brute Force:" << endl;
    cout << "cpuTime = " << cpuTimeB << " elapsedTime = " << elapsedTimeB << endl;
    cout << "Start Index: " << bruteStart << ", End Index: " << bruteEnd << ", Sum: " << bruteSum << endl;

    //show results of Max Sub
    cout << "Recursive:" << endl;
    cout << "cpuTime = " << cpuTimeM << " elapsedTime = " << elapsedTimeM << endl;
    cout << "Start Index: " << recursiveStart << ", End Index: " << recursiveEnd << ", Sum: " << recursiveSum << endl;

    //show results for Kadane
    cout << "Kadane:" << endl;
    cout << "cpuTime = " << cpuTimeK << " elapsedTime = " << elapsedTimeK << endl;
    cout << "Start Index: " << kadaneStart << ", End Index: " << kadaneEnd << ", Sum: " << kadaneSum << endl;



    return 0;
}
/*
 * ThreeSum.cpp
 *
 *  Created on: 11-Feb-2015
 *      Author: shashi
 */

#ifndef THREESUM_CPP_
#define THREESUM_CPP_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class ThreeSum {
public:
	void insertionSort(int arrayToBeSorted[],int arrSize);
	void selectionSort(int arrayToBeSorted[],int arrSize);
	void mergeSort(int arrayToBeSorted[],int arrSize);
	bool splitArray(int inputArr[],int rightArr[],int leftArr[],int inputArrSize);
	void sortAndmergeArray(int outputArr[],int rightArr[],int leftArr[],int inputArrSize);
};

#endif /* THREESUM_CPP_ */

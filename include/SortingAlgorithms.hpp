/*
 * SortingAlgorithms.hpp
 *
 *  Created on: 29-Mar-2015
 *      Author: shashi
 */

#ifndef SORTINGALGORITHMS_HPP_
#define SORTINGALGORITHMS_HPP_

#include <stdio.h>
#include <iostream>
#include <string>

class SortingAlgorithms {
public:
	void QuickSort(int inputArray[],int low,int arrSize);

private:
	void swapElements(int inputArray[], int firstElement,int secondElement);
	int partition_array( int inputArray[],int low,int arrSize);
};



#endif /* SORTINGALGORITHMS_HPP_ */

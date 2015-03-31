/*
 * SortingAlgorithms.cpp
 *
 *  Created on: 29-Mar-2015
 *      Author: shashi
 */
#include "include/SortingAlgorithms.hpp"
#include <algorithm>
#include <iterator>

int quick_sort_iter=0;
void SortingAlgorithms::swapElements(int inputArray[], int firstelement,int secondElement)
{
	if(firstelement!=secondElement)
	{
		inputArray[firstelement] = inputArray[secondElement] + inputArray[firstelement];
		inputArray[secondElement] = inputArray[firstelement] - inputArray[secondElement];
		inputArray[firstelement] = inputArray[firstelement] - inputArray[secondElement];
	}
}

int SortingAlgorithms::partition_array( int inputArray[],int low,int arrSize)
{
	int rightArrIndex = 1, leftArrIndex = arrSize - 1;

	while (rightArrIndex != leftArrIndex)
	{
		for (; rightArrIndex < leftArrIndex; rightArrIndex++)
		{
			quick_sort_iter++;
			if (inputArray[rightArrIndex] > inputArray[low])
				break;
		}

		for (; leftArrIndex > rightArrIndex; leftArrIndex--)
		{
			quick_sort_iter++;
			if (inputArray[leftArrIndex] < inputArray[low])
				break;
		}

		if (rightArrIndex < leftArrIndex)
			swapElements(inputArray, rightArrIndex, leftArrIndex);
		else
			break;
	}
	if (rightArrIndex ==leftArrIndex)
	{
		if(inputArray[rightArrIndex]<inputArray[low])
			swapElements(inputArray, rightArrIndex, low);
	}
	return rightArrIndex;
}

/* using c++11 in eclipse
 * http://stackoverflow.com/questions/17457069/enabling-c11-in-eclipse-juno-kepler-luna-cdt
 */


void SortingAlgorithms::QuickSort(int inputArray[],int low,int arrSize)
{
	srand (time(NULL));
	int pivotElement = arrSize-1;
	if(arrSize<=1)
		return;
	swapElements(inputArray, pivotElement,0);
	int pos=partition_array(inputArray,low,arrSize);
	QuickSort(inputArray,low,pos);
	QuickSort(inputArray+pos,low,arrSize-(pos));
}


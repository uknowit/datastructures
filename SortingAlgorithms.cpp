/*
 * SortingAlgorithms.cpp
 *
 *  Created on: 29-Mar-2015
 *      Author: shashi
 */
#include "include/SortingAlgorithms.hpp"
#include <algorithm>
#include <iterator>

void SortingAlgorithms::swapElements(int inputArray[], int firstelement,int secondElement)
{
	std::cout<<"Swap pos::"<<firstelement<<" ::"<<secondElement<<std::endl;
	std::cout<<"Swap element::"<<inputArray[firstelement]<<" ::"<<inputArray[secondElement]<<std::endl;
	if(firstelement!=secondElement)
	{
		inputArray[firstelement] = inputArray[secondElement] + inputArray[firstelement];
		inputArray[secondElement] = inputArray[firstelement] - inputArray[secondElement];
		inputArray[firstelement] = inputArray[firstelement] - inputArray[secondElement];
	}
	std::cout<<"Swap element::"<<inputArray[firstelement]<<" ::"<<inputArray[secondElement]<<std::endl;
}

int SortingAlgorithms::partition_array( int inputArray[],int low,int arrSize)
{
	if(arrSize==1)
		return 0;
	int rightArrIndex = 1, leftArrIndex = arrSize - 1;
	while (rightArrIndex != leftArrIndex)
	{
		for (; rightArrIndex < leftArrIndex; rightArrIndex++)
		{
			if (inputArray[rightArrIndex] > inputArray[low])
				break;
		}
		for (; leftArrIndex > rightArrIndex; leftArrIndex--)
		{
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
		swapElements(inputArray, rightArrIndex-1, low);
		return rightArrIndex-1;
	}
	else
	{
		swapElements(inputArray,rightArrIndex,low);
		return rightArrIndex;
	}
}

/* using c++11 in eclipse
 * http://stackoverflow.com/questions/17457069/enabling-c11-in-eclipse-juno-kepler-luna-cdt
 */


void SortingAlgorithms::QuickSort(int inputArray[],int low,int arrSize)
{
	srand (time(NULL));
	int pivotElement = rand()%(arrSize-1);
	std::cout<<"Quick sort pivot element ::"<<pivotElement<<std::endl;
	swapElements(inputArray, pivotElement,0);
	if(arrSize<=low)
		return;
	int pos=partition_array(inputArray,low,arrSize);
	QuickSort(inputArray,low,pos+1);
	QuickSort(inputArray+pos+1,pos+1,arrSize-(pos+1));
}


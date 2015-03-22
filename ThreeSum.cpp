/*
 * ThreeSum.cpp
 *
 *  Created on: 11-Feb-2015
 *      Author: shashi
 */

#include "include/ThreeSum.hpp"

void ThreeSum::insertionSort(int arrayToBeSorted[],int arrSize)
{
	int noOfIterations=0;
	for(int loopIndex=1;loopIndex<arrSize;loopIndex++)
	{
		int compareIndex=loopIndex-1;
		int comparisionKey=arrayToBeSorted[loopIndex];
		while(compareIndex>=0 && arrayToBeSorted[compareIndex]>comparisionKey)
		{
			arrayToBeSorted[compareIndex+1]=arrayToBeSorted[compareIndex];
			compareIndex=compareIndex-1;
			noOfIterations++;
		}
		arrayToBeSorted[compareIndex+1]=comparisionKey;
	}
	std::cout<<"Sorted array of size...."<<arrSize<<" No of iterations for sorting  array is"<<noOfIterations<<std::endl;
	for(int index=0;index<arrSize;index++)
		std::cout<<arrayToBeSorted[index]<<" "<<std::endl;
}

void ThreeSum::selectionSort(int arrayToBeSorted[],int arrSize)
{
	int noOfIterations=0;
	int smallestItemIndex=0;
	for(int loopIndex=0;loopIndex<arrSize;loopIndex++)
	{
		smallestItemIndex=loopIndex;
		for(int index=loopIndex+1;index<arrSize;index++)
		{
			if(arrayToBeSorted[index] <arrayToBeSorted[smallestItemIndex])
			{
				smallestItemIndex=index;
			}
			noOfIterations++;
		}
		if(smallestItemIndex!=loopIndex)
		{
			arrayToBeSorted[loopIndex]+=arrayToBeSorted[smallestItemIndex];
			arrayToBeSorted[smallestItemIndex]=arrayToBeSorted[loopIndex]-arrayToBeSorted[smallestItemIndex];
			arrayToBeSorted[loopIndex]-=arrayToBeSorted[smallestItemIndex];
		}
	}
	std::cout<<"Sorted array of size...."<<arrSize<<" No of iterations for sorting array"<<noOfIterations<<std::endl;
	for(int index=0;index<arrSize;index++)
			std::cout<<arrayToBeSorted[index]<<" "<<std::endl;
}

void ThreeSum::splitArray(int inputArray[],int rightArr[],int leftArr[],int arrSize)
{
	int mid = arrSize/2;
	for(int index=0;index<mid;index++)
		rightArr[index]=inputArray[index];
	for(int index=mid;index<arrSize;index++)
		leftArr[index-mid]=inputArray[index];
}

void ThreeSum::sortAndmergeArray(int outputArray[],int rightArr[],int leftArr[],int arrSize)
{
	int mid=arrSize/2;
	int arrayIndex=0,rightIndex=0,leftIndex=0;
	while(rightIndex<=mid-1 && leftIndex<=arrSize-mid-1)
	{
		if(rightArr[rightIndex] < leftArr[leftIndex])
			outputArray[arrayIndex++]=rightArr[rightIndex++];
		else
			outputArray[arrayIndex++]=leftArr[leftIndex++];
	}
	while(rightIndex<mid)
		outputArray[arrayIndex++]=rightArr[rightIndex++];
	while(leftIndex<arrSize-mid)
		outputArray[arrayIndex++]=leftArr[leftIndex++];

}

void ThreeSum::mergeSort(int outputArray[],int arrayToBeSorted[],int arrSize)
{
	bool bottomsUp=false;
	int mid=arrSize/2;
	int rightArr[mid],leftArr[arrSize-mid];
    if((!(arrSize==0 || arrSize==1)) && !bottomsUp)
    {
    	splitArray(arrayToBeSorted,rightArr,leftArr,arrSize);
    	mergeSort(outputArray,rightArr,mid);
    	mergeSort(outputArray,leftArr,arrSize-mid);
    	insertionSort(rightArr,mid);
    	insertionSort(leftArr,arrSize-mid);
    	sortAndmergeArray(outputArray,rightArr,leftArr,arrSize);
    }
}

void ThreeSum::printArray(int inputArray[],int arrSize)
{
	for(int index=0;index<arrSize;index++)
		std::cout<<inputArray[index]<<std::endl;
}

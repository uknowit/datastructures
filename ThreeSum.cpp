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

bool ThreeSum::splitArray(int inputArray[],int rightArr[],int leftArr[],int arrSize)
{
	int mid = arrSize/2;
	bool returnValue=false;
	if(mid!=1)
	{
		for(int index=0;index<mid;index++)
			rightArr[index]=inputArray[index];
		for(int index=mid;index<arrSize;index++)
			leftArr[index-mid]=inputArray[index];
	}
	else
	{
		returnValue=true;
	}
	return returnValue;
}

void ThreeSum::sortAndmergeArray(int outputArray[],int rightArr[],int leftArr[],int arrSize)
{
	int arrayIndex=0;
	int rightArrIndex,leftArrIndex=0;
	int mid = arrSize/2;
	leftArrIndex=mid;
	while(arrayIndex < arrSize)
	{
		if((rightArrIndex< mid-1 && leftArrIndex<arrSize) && (rightArr[rightArrIndex] > leftArr[leftArrIndex]))
			outputArray[arrayIndex]= leftArr[leftArrIndex++];
		else if ((rightArrIndex<=mid-1 && leftArrIndex<arrSize) && ( rightArr[rightArrIndex] > leftArr[leftArrIndex]))
			outputArray[arrayIndex]= rightArr[rightArrIndex++];
		else if(leftArrIndex==arrSize-1)
			outputArray[arrayIndex]= rightArr[rightArrIndex++];
		else if(rightArrIndex==mid-1)
			outputArray[arrayIndex]= leftArr[leftArrIndex++];
		arrayIndex++;
	}
}

void ThreeSum::mergeSort(int arrayToBeSorted[],int arrSize)
{
	int mid=arrSize/2;
	int rightArr[mid];
	int leftArr[arrSize-mid];
	while(!splitArray(arrayToBeSorted,rightArr,leftArr,arrSize))
	{
		mergeSort(rightArr,mid);
		mergeSort(leftArr,arrSize);
	}
	sortAndmergeArray(arrayToBeSorted,rightArr,leftArr,arrSize);
}

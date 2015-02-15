/*
 * ThreeSum.cpp
 *
 *  Created on: 11-Feb-2015
 *      Author: shashi
 */

#include "../include/ThreeSum.hpp"

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
	for(int loopIndex=0;loopIndex<arrSize;loopIndex++)
	{
		int smallestItem=arrayToBeSorted[loopIndex];
		for(int index=loopIndex+1;index<arrSize;index++)
		{
			if(arrayToBeSorted[index] <smallestItem)
			{
				smallestItem=arrayToBeSorted[index];
				arrayToBeSorted[loopIndex]+=arrayToBeSorted[index];
				arrayToBeSorted[index]=arrayToBeSorted[loopIndex]-arrayToBeSorted[index];
				arrayToBeSorted[loopIndex]-=arrayToBeSorted[index];
			}
			noOfIterations++;
		}
	}
	std::cout<<"Sorted array of size...."<<arrSize<<" No of iterations for sorting array"<<noOfIterations<<std::endl;
	for(int index=0;index<arrSize;index++)
			std::cout<<arrayToBeSorted[index]<<" "<<std::endl;
}
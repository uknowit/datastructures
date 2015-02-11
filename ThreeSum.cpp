/*
 * ThreeSum.cpp
 *
 *  Created on: 11-Feb-2015
 *      Author: shashi
 */

#include "../include/ThreeSum.hpp"

void ThreeSum::insertionSort(int arrayToBeSorted[],int arrSize)
{
	for(int loopIndex=1;loopIndex<arrSize;loopIndex++)
	{
		int compareIndex=loopIndex-1;
		int comparisionKey=arrayToBeSorted[loopIndex];
		while(compareIndex>=0 && arrayToBeSorted[compareIndex]>comparisionKey)
		{
			arrayToBeSorted[compareIndex+1]=arrayToBeSorted[compareIndex];
			compareIndex=compareIndex-1;
		}
		arrayToBeSorted[compareIndex+1]=comparisionKey;
	}
	std::cout<<"Sorted array of size...."<<arrSize<<std::endl;
	for(int index=0;index<arrSize;index++)
		std::cout<<arrayToBeSorted[index]<<" "<<std::endl;
}

/*
 * WeightedUnion.cpp
 *
 *  Created on: 04-Feb-2015
 *      Author: shashi
 */
#include "../include/WeightedUnion.hpp"



void WeightedUnion::m_weightedUnion(const int firstPoint,const int secondPoint)
{
	int root_first_point=firstPoint;
	int root_second_point=secondPoint;
	m_findRoot(root_first_point);
	m_findRoot(root_second_point);
    if(root_first_point!=root_second_point)
    {
    	if(m_sizeArray[root_first_point]<m_sizeArray[root_second_point])
    	{
    		m_IndexArray[firstPoint]=root_second_point;
    		m_sizeArray[secondPoint]+=m_sizeArray[firstPoint];
    	}
    	else
    	{
    		m_IndexArray[secondPoint]=root_first_point;
    	    m_sizeArray[firstPoint]+=m_sizeArray[secondPoint];
    	}

    }
}

void WeightedUnion::m_findRoot(int & localFirstPoint)
{
    while(localFirstPoint != m_IndexArray[localFirstPoint])
    {
        localFirstPoint = m_IndexArray[m_IndexArray[localFirstPoint]];
    }
}

bool WeightedUnion::m_find(const int firstPoint,const int secondPoint)
{
	bool connected=false;
	int root_first_point=firstPoint;
	int root_second_point=secondPoint;
	m_findRoot(root_first_point);
	m_findRoot(root_second_point);
	if(root_first_point==root_second_point)
		connected=true;
	return connected;
}

void WeightedUnion::m_printArray()
{
	std::cout<<"Index array::"<<std::endl;
	for(int innerIndex=0;innerIndex<m_arrSize;innerIndex++)
			std::cout<<m_IndexArray[innerIndex]<<" ";
		std::cout<<""<<std::endl;

	std::cout<<"Size array::"<<std::endl;
	for(int innerIndex=0;innerIndex<m_arrSize;innerIndex++)
				std::cout<<m_sizeArray[innerIndex]<<" ";
	std::cout<<""<<std::endl;
}

void WeightedUnion::init()
{
	m_IndexArray=new int[m_arrSize];
	m_sizeArray=new int[m_arrSize];
	for(int index=0;index<m_arrSize;index++)
	{
		m_IndexArray[index]=index;
	}
	for(int index=0;index<m_arrSize;index++)
	{
		m_sizeArray[index]=index;
	}
}

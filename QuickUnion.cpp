/*
 * QuickUnion.cpp
 *
 *  Created on: 03-Feb-2015
 *      Author: shashi
 */

#include "../include/QuickUnion.hpp"

void QuickUnion::m_union(const int firstPoint,const int secondPoint)
{
	if(firstPoint<m_arrSize && secondPoint<m_arrSize)
	{
		m_IndexArray[firstPoint]=m_IndexArray[secondPoint];
	}
	else
	{
		std::cout<<"Points are outside the array boundary"<<std::endl;
	}
}

void QuickUnion::findRoot(int & localFirstPoint)
{
    while(localFirstPoint != m_IndexArray[localFirstPoint])
    {
        localFirstPoint = m_IndexArray[m_IndexArray[localFirstPoint]];
    }
}

bool QuickUnion::m_find(const int firstPoint,const int secondPoint)
{
	bool connected=false;
	int root_first_point=firstPoint;
	int root_second_point=secondPoint;
	findRoot(root_first_point);
    findRoot(root_second_point);
	if(root_first_point==root_second_point)
		connected=true;
	return connected;
}

void QuickUnion::m_printArrayContent()
{
	for(int innerIndex=0;innerIndex<m_arrSize;innerIndex++)
		std::cout<<m_IndexArray[innerIndex]<<" ";
	std::cout<<""<<std::endl;
}

void QuickUnion::init()
{
	m_IndexArray=new int[m_arrSize];
	for(int index=0;index<m_arrSize;index++)
		m_IndexArray[index]=index;
}

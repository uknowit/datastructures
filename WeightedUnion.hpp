/*
 * WeightedUnion.hpp
 *
 *  Created on: 04-Feb-2015
 *      Author: shashi
 */

#ifndef WEIGHTEDUNION_HPP_
#define WEIGHTEDUNION_HPP_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class WeightedUnion {
public:
	WeightedUnion(int size):m_arrSize(size){init();}
	~WeightedUnion(){delete [] m_IndexArray;delete[] m_sizeArray;}
	void m_weightedUnion(const int firstPoint,const int secondPoint);
	bool m_find(const int firstPoint,const int secondPoint);
	void m_printArray();
private:
	void m_findRoot(int & localFirstPoint);
	void init();
	int m_arrSize;
	int *m_IndexArray,*m_sizeArray;
};

#endif /* WEIGHTEDUNION_HPP_ */

/*
 * QuickUnion.hpp
 *
 *  Created on: 03-Feb-2015
 *      Author: shashi
 */

#ifndef QUICKUNION_HPP_
#define QUICKUNION_HPP_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class QuickUnion {
public:
		QuickUnion(int size):m_arrSize(size){init();}
		~QuickUnion(){delete[] m_IndexArray;}
		void m_union(const int firstPoint,const int secondPoint);
		bool m_find(const int firstPoint,const int secondPoint);
		void m_printArrayContent();
private:
		void init();
		int m_arrSize;
		int* m_IndexArray;
};

#endif /* QUICKUNION_HPP_ */

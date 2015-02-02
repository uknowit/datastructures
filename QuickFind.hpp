#ifndef _QUICK_FIND_HPP
#define _QUICK_FIND_HPP

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

class QuickFind {
	public:
		QuickFind(int size):m_arrSize(size){init();}
		~QuickFind(){delete[] m_IndexArray;}
		void m_union(int firstPoint,int secondPoint);
		bool m_connected(int firstPoint,int secondPoint);
		void m_printArrayContent();
	private:
		void init();
    void m_handleNewSecondPoint(int secondPoint, int firstPoint);
		int m_arrSize;
		int* m_IndexArray;
};

#endif

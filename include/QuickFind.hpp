#ifndef _QUICK_FIND_HPP
#define _QUICK_FIND_HPP

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <memory.h>

class QuickFind {
	public:
		QuickFind(int size):m_arrSize(size){init();}
		QuickFind(const QuickFind& otherQuickFind)
		{
			this->m_arrSize=otherQuickFind.m_arrSize;
			this->m_IndexArray=new int[m_arrSize];
			memcpy(this->m_IndexArray,otherQuickFind.m_IndexArray,m_arrSize);
		}
		QuickFind& operator=(const QuickFind& otherQuickFind);
		~QuickFind(){delete[] m_IndexArray;}
		void m_union(int firstPoint,int secondPoint);
		bool m_connected(int firstPoint,int secondPoint);
		void m_printArrayContent();
	private:
		void init();
		void m_handleNewSecondPoint(int storePoint, int secondPoint);
		int m_arrSize;
		int* m_IndexArray;
};

#endif

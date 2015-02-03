#include "../include/QuickFind.hpp"
#include <string>

void QuickFind::m_handleNewSecondPoint(int secondPoint, int firstPoint)
{
    m_IndexArray[secondPoint] = secondPoint;
    for(int index = 0;index < m_arrSize;index++){
        if(m_IndexArray[firstPoint] == m_IndexArray[index] && (index != firstPoint))
            m_IndexArray[index] = m_IndexArray[secondPoint];
    }
    m_IndexArray[firstPoint] = secondPoint;
}

void QuickFind::m_union(int firstPoint,int secondPoint)
{
	if(firstPoint<m_arrSize && secondPoint<m_arrSize)
	{
		if(m_IndexArray[firstPoint]==0 && m_IndexArray[secondPoint]==0)
		{
			m_IndexArray[secondPoint]=secondPoint;
			m_IndexArray[firstPoint]=m_IndexArray[secondPoint];
		}
		else if(m_IndexArray[firstPoint]==0)
		{
			m_IndexArray[firstPoint]=m_IndexArray[secondPoint];
		}
		else if(m_IndexArray[secondPoint]==0)
		{
			m_IndexArray[secondPoint]=m_IndexArray[firstPoint];
		}
		else
		{
			m_handleNewSecondPoint(secondPoint, firstPoint);
		}
	}
	else
	{
		std::cout<<"Points to union-ed are out of array range.."<<std::endl;
	}
}

bool QuickFind::m_connected(int firstPoint,int secondPoint)
{
	bool connected=false;
	if(m_IndexArray[firstPoint]==m_IndexArray[secondPoint])
		connected=true;
	return connected;

}

void QuickFind::init()
{
	m_IndexArray = new int[m_arrSize];
	for(int index=0;index<m_arrSize;index++)
		m_IndexArray[index]=0;

}

void QuickFind::m_printArrayContent()
{
	for(int innerIndex=0;innerIndex<m_arrSize;innerIndex++)
		std::cout<<m_IndexArray[innerIndex]<<" ";
	std::cout<<""<<std::endl;
}

int main()
{
	int inputOption,arraySize;
	std::cout<<"Please enter the array size"<<std::endl;
	std::cin>>arraySize;
	QuickFind quickFindExample(arraySize);
	do {
		int firstPoint,secondPoint;
		std::cout<<"Please select an option for operation to be performed..."<<std::endl;
		std::cout<<"1.Union"<<std::endl;
		std::cout<<"2.Connected"<<std::endl;
		std::cout<<"3.Print array content"<<std::endl;
		std::cout<<"4.Exit"<<std::endl;
		std::cout<<"Please enter your option:";
		std::cin>>inputOption;
		switch(inputOption)
		{
		case 1:
				std::cout<<"You have entered option 1"<<std::endl;
				std::cout<<"Please enter the first point"<<std::endl;
				std::cin>>firstPoint;
				std::cout<<"Please enter the second point"<<std::endl;
				std::cin>>secondPoint;
				quickFindExample.m_union(firstPoint,secondPoint);
				break;
		case 2:
				std::cout<<"You have entered option 2"<<std::endl;
				std::cout<<"Please enter the first point"<<std::endl;
				std::cin>>firstPoint;
				std::cout<<"Please enter the second point"<<std::endl;
				std::cin>>secondPoint;
				std::cout<<"First point is"<<(quickFindExample.m_connected(firstPoint,secondPoint)?
						" ":" not")<<" connected to second point"<<std::endl;
				break;
		case 3:
				std::cout<<"You have entered option 3"<<std::endl;
				quickFindExample.m_printArrayContent();
				break;
		case 4:
				std::cout<<"You have entered option 4"<<std::endl;
				std::cout<<"Bye...."<<std::endl;
				break;
		default:
			std::cout<<"You have entered an invalid option!!!"<<std::endl;
		}
	}while(inputOption<4 && inputOption>0);
}
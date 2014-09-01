/**
 *	test.cpp
 *	
 *	Test program for the queue data structure
 */



#include <iostream>
#include "queue.h"


int main(int argc, char* argv[])
{
	Queue q;

	q.enqueue(0);
	q.enqueue(1);
	q.enqueue(2);

	for(int i = 0; i < 3; i++)
	{
		std::cout << q.dequeue() << " ";
	}
	std::cout << "\n";


	return 0;
}	

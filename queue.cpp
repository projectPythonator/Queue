/**
 *	Queue.cpp
 *		
 *	Basic queue data structure
 *
 *	Author: Edward Ruzek	Sep 1, 2014
 */
#include <iostream>
#include "queue.h"

/**
 *	Constructor:
 *	When no parameter is passed, Queue attains a default size of 10
 */
Queue::Queue()
{
	MAX_SIZE = 10;
	array = new int[MAX_SIZE];

	counter = 0;
	head = 0;
	tail = 0;
}

Queue::Queue(int size)
{
	MAX_SIZE = size;
	array = new int[MAX_SIZE];

	counter = 0;
	head = 0;
	tail = 0;
}


Queue::~Queue()
{
	delete array;
}

void Queue::enqueue(int num)
{
	array[tail] = num;

	counter++;

	if (tail < MAX_SIZE)
		tail++;
	else
		tail = 0;
}


int Queue::dequeue()
{
	int num = array[head];
	
	counter--;

	if (head < MAX_SIZE)
		head++;
	else
		head = 0;
		
	return num;
}

int Queue::size()
{
	return counter;
}


void Queue::test()
{
	for(int i = 0; i < MAX_SIZE - 1; i++)
	{
		this->enqueue(i);
		std::cout << i << " ";
	}
	std::cout << "\n";
	
	for(int i = 0; i < MAX_SIZE - 2; i++)
	{
		std::cout << this->dequeue() << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < MAX_SIZE - 1; i++)
	{
		int enq = 10*i;
		this->enqueue(enq);
		std::cout << enq << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < MAX_SIZE; i++)
	{
		std::cout << this->dequeue() << " ";
	}
	std::cout << "\n"; 
}

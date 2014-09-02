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
	tail++;
}


int Queue::dequeue()
{
	int num = array[head];

	counter--;
	head++;
	
	return num;
}

int Queue::size()
{
	return counter;
}


void Queue::test()
{
	for(int i = 0; i < this->MAX_SIZE; i++)
	{
		this->enqueue(i);
	}

	for(int i = 0; i < this->MAX_SIZE; i++)
	{
		std::cout << this->dequeue() << "\n";
	}
}

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

	head = 0;
	tail = 0;
	isFull = false;
}

Queue::Queue(int size)
{
	MAX_SIZE = size;
	array = new int[MAX_SIZE];

	head = 0;
	tail = 0;
	isFull = false;
}


Queue::~Queue()
{
	delete array;
}

void Queue::enqueue(int num)
{
	array[tail] = num;

	if (tail < MAX_SIZE - 1)
		tail++;
	else
		tail = 0;

	if (head == tail)
		isFull = true;
}


int Queue::dequeue()
{
	int num = array[head];

	if (head < MAX_SIZE - 1)
		head++;
	else
		head = 0;

	if (head == tail)
		isFull = false;

	return num;
}

int Queue::size()
{
	if (tail > head)
		return (tail - head);
	else if (tail < head)
		return (MAX_SIZE - (head - tail));
	else if (isFull)
		return MAX_SIZE;
	else
		return 0;
}


void Queue::test()
{
	for(int i = 0; i < MAX_SIZE - 1; i++)
	{	
		int enq = i;
		this->enqueue(enq);
		std::cout << enq << ":" << this->size() << " ";
	}
	std::cout << "\n";
	
	for(int i = 0; i < MAX_SIZE - 2; i++)
	{
		int deq = this->dequeue();
		std::cout << deq << ":" << this->size() << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < MAX_SIZE - 1; i++)
	{
		int enq = 10*i;
		this->enqueue(enq);
		std::cout << enq << ":" << this->size() << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < MAX_SIZE; i++)
	{
		int deq = this->dequeue();
		std::cout << deq << ":" << this->size() << " ";
	}
	std::cout << "\n"; 
}

/**
 *	Queue.cpp
 *		
 *	Basic queue data structure
 *
 *	Author: Edward Ruzek	Sep 1, 2014
 */
#include <iostream>
#include <assert.h>

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
	delete[] array;
}

void Queue::enqueue(int num)
{
	if (isFull && size() == MAX_SIZE)
		resize(2 * MAX_SIZE);

	array[tail] = num;

	++tail % MAX_SIZE;

	if (head == tail)
		isFull = true;
}


int Queue::dequeue()
{ 
	//assert(head != tail && !isFull && "dequeue from an empty array");

	if (size() == MAX_SIZE/4)
		resize(MAX_SIZE/2);
	
	int num = array[head];

	++head % MAX_SIZE;

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

void Queue::resize(int num_size)
{
	int* temp = new int[num_size];

	for (int i = 0; i < size(); i++)
	{
		int idx = (i + head) % MAX_SIZE;
		temp[i] = array[idx];
	}

	delete[] array;
	array = temp;

	head = 0;
	tail = size();
	MAX_SIZE = num_size;
	isFull = false;
}


void Queue::test()
{
	for (int i = 0; i < 5; i++)
	{
		enqueue(i);
	}

	for (int i = 0; i < 4; i++)
	{
		std::cout << dequeue() << " ";
	}
	std::cout << "\n\n";

	for (int i = 0; i < 4; i++)
	{
		enqueue(i);
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << dequeue() << " ";
	}
	std::cout << "\n\n";
}

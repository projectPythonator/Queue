/**
 *	Queue.cpp
 *		
 *	Basic queue data structure
 *
 *	Author: Edward Ruzek	Sep 1, 2014
 */

#include "queue.h"

/**
 *	Constructor:
 *	When no parameter is passed, Queue attains a default size of 10
 */
Queue::Queue()
{
	MAX_SIZE = 10;
	counter = 0;
	array = new int[MAX_SIZE];
}

Queue::Queue(int size)
{
	MAX_SIZE = size;
	counter = 0;
	array = new int[MAX_SIZE];
}


Queue::~Queue()
{
	delete array;
}

void Queue::enqueue(int num)
{
	array[counter] = num;
	counter++;
}


int Queue::dequeue()
{
	counter--;
	
	int num = array[counter];
	return num;
}

int Queue::size()
{
	return counter;
}

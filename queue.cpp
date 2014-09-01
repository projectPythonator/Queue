#include "queue.h"



Queue::Queue()
{
	MAX_SIZE = 10;
	counter = 0;
	array = new array[MAX_SIZE];
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
	int num = array[counter];
	counter--;
	return num;
}

int Queue::size()
{
	return counter;
}

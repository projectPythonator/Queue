/**
 *	test.cpp
 *	
 *	Test program for the queue data structure
 */

#include <stdlib.h>
#include "queue.h"


int main(int argc, char *argv[])
{
	Queue q( atoi( argv[0] ) );

	q.test();
	
	return 0;
}	

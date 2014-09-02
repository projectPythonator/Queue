#ifndef QUEUE_H
#define QUEUE_H



class Queue
{
	private:
		int MAX_SIZE;
		int* array;

		int counter;
		int head;
		int tail;

	public:
		Queue();
		Queue(int);
		~Queue();
		void enqueue(int);
		int dequeue();
		int size(); 

		void test();

};

#endif

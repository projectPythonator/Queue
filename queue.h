#ifndef QUEUE_H
#define QUEUE_H



class Queue
{
	private:
		int MAX_SIZE;
		int counter;
		int* array;

	public:
		Queue();
		Queue(int);
		~Queue();
		void enqueue(int);
		int dequeue();
		int size(); 

};

#endif

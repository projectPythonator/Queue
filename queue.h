#ifndef QUEUE_H
#define QUEUE_H



class Queue
{
	private:
		int MAX_SIZE;
		int* array;

		int head;
		int tail;
		bool isFull;

	public:
		Queue();
		Queue(int);
		~Queue();
		void enqueue(int);
		int dequeue();
		int size(); 
		void resize(int);

		void test();

};

#endif

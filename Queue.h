#ifndef QUEUE_
#define QUEUE_

#include <iostream>

using namespace std;


class Queue{
	public:
		struct Node;
		typedef Node* nodePtr;
		struct Node{
			int data;
			nodePtr next;
			nodePtr prev;

		};

		Queue();
		~Queue();
		Queue& operator=(const Queue& other);
		Queue(const Queue& other);

		void Enqueue(int);
        int Dequeue();
        bool IsEmpty();
		void Print();


	private:
		nodePtr head;
		nodePtr current;
		nodePtr tail;
};
#endif

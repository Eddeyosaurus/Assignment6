#ifndef STACK_
#define STACK_

#include <iostream>

using namespace std;


class Stack{
	public:
		struct Node;
		typedef Node* nodePtr;
		struct Node{
			int data;
			nodePtr next;
			nodePtr prev;

		};

		Stack();
		~Stack();
		Stack& operator=(const Stack& other);
		Stack(const Stack& other);

		void Push(int i);
        int Pop();
        bool IsEmpty();
		void Print();


	private:
		nodePtr head;
		nodePtr current;
		nodePtr tail;
        int size;
};
#endif

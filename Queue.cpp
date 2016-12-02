#include "Queue.h"




Queue::Queue()
{
	head = NULL;
	tail = NULL;
	current = NULL;
}




Queue::~Queue()
{
	current = tail;

	while(current){
		tail = tail->prev;
		delete current;
		current = tail;
	}
}




Queue::Queue(const Queue& other)
{
	if(other.head)
	{
		nodePtr otherPtr;
		otherPtr = other.head;
		head = new Node;
		current = head;

		current->data = otherPtr->data;
		otherPtr = otherPtr->next;
		
		while(otherPtr)
		{
			current->next = new Node;
			current = current->next;
			current->data = otherPtr->data;
			tail = current;
			otherPtr = otherPtr->next;
		}
	}
	else{
		head = NULL;
		tail = NULL;
		current = NULL;
	}
	
}




Queue& Queue::operator=(const Queue& other)
{
	if(other.head)
	{
		nodePtr otherPtr;
		otherPtr = other.head;
		head = new Node;
		current = head;

		current->data = otherPtr->data;
		otherPtr = otherPtr->next;
		
		while(otherPtr)
		{
			current->next = new Node;
			current = current->next;
			current->data = otherPtr->data;
			tail = current;
			otherPtr = otherPtr->next;
		}
	}
	else{
		head = NULL;
		tail = NULL;
		current = NULL;
	}
}




bool Queue::IsEmpty()
{
    if(head)
        return false;
    else if(!head)
        return true;
}




void Queue::Enqueue(int i)
{
	nodePtr temp = new Node;
	temp->data = i;

	if(!head){
		head = temp;
        tail = head;
        head->next = NULL;
        head->prev = NULL;
        
    }
	else{
		temp->next = head;
        head->prev = temp;
        head = temp;
        head->prev = NULL;
    }
}




int Queue::Dequeue()
{
    int temp;
    
    if(head && tail == head)
    {
        temp = head->data;
        delete head;
        head = NULL;
        tail = NULL;
    }
    else if(tail){
        temp = tail->data;
        current = tail;
        tail = tail->prev;
        delete current;
    }
    
    return temp;
}
    



void Queue::Print()
{
	current = tail;

	while(current)
	{
		cout << current->data << " ";
		current = current->prev;
	}
}

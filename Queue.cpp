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




void Queue::Enqueue(int i, int w)
{
	nodePtr comparison = head;
	nodePtr temp = new Node;
	temp->data = i;
	temp->weight = w;
	temp->prev = NULL;
	temp->next = NULL;


	if(!head || temp->weight < head->weight)
	{
		if(!head){
			temp->next = NULL;
			temp->prev = NULL;
			tail = head;
		}
		else
		{
			head->prev = temp;
			temp->prev = NULL;
			temp->next = head;

		}

		head = temp; 	
    }
	else{
		while(comparison->next && comparison->next->weight <= temp->weight)
			comparison = comparison->next;
		temp->next = comparison->next;

        if(comparison->next)
        {
        	comparison->next->prev = temp;
        }

        comparison->next = temp;
        temp->prev = comparison;

        if(!temp->next)
        	tail = temp;
    }
}




int Queue::Dequeue()
{
	int ret = head->data;
    nodePtr temp = head;
    head = head->next;
    
    if(head)
    	head->prev = NULL;

    delete temp;

    return ret;
}
    



void Queue::Print()
{
	current = head;

	while(current)
	{
		cout << current->data << " ";
		current = current->next;
	}
}

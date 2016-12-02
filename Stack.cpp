#include "Stack.h"


Stack::Stack()
{
	head = NULL;
	tail = NULL;
	current = NULL;
    size = 0;
}

Stack::~Stack()
{
	current = head;

	while(current){
		head = head->next;
		delete current;
		current = head;
	}
}

Stack::Stack(const Stack& other)
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

Stack& Stack::operator=(const Stack& other)
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

void Stack::Push(int i)
{
	nodePtr temp = new Node;
	temp->data = i;

	current = head;

	if(!head){
		head = temp;
        tail = head;
        head->next = NULL;
        head->prev = NULL;
        
    }
	else{
		temp->next = head;
        head = temp;
    }
    size++;
}

int Stack::Pop()
{
    int temp;
    
    current = head;
    
    if(head){
        head = head->next;
    
        temp = current->data;
    
        delete current;
    }
    size--;
    
    return temp;
}




bool Stack::IsEmpty()
{
    if(size == 0)
        return true;
    else 
        return false;
}
    


void Stack::Print()
{
	current = head;

	while(current)
	{
		cout << current->data << " ";
		current = current->next;
	}
}

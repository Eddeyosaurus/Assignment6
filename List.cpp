#include "List.h"


List::List()
{
	head = NULL;
	tail = NULL;
	current = NULL;
}

List::~List()
{
	current = tail;

	while(current){
		tail = tail->prev;
		delete current;
		current = tail;
	}
}

List::List(const List& other)
{
	if(other.head)
	{
		nodePtr otherPtr;
		otherPtr = other.head;
		head = new Node;
		current = head;

		current->data = otherPtr->data;
		current->weight = otherPtr->weight;
		otherPtr = otherPtr->next;
		
		while(otherPtr)
		{
			current->next = new Node;
			current = current->next;
			current->data = otherPtr->data;
			current->weight = otherPtr->weight;
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

List& List::operator=(const List& other)
{
	if(other.head)
	{
		nodePtr otherPtr;
		otherPtr = other.head;
		head = new Node;
		current = head;

		current->data = otherPtr->data;
		current->weight = otherPtr->weight;
		otherPtr = otherPtr->next;
		
		while(otherPtr)
		{
			current->next = new Node;
			current = current->next;
			current->data = otherPtr->data;
			current->weight = otherPtr->weight;
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

void List::Insert(int i, int w)
{
	nodePtr temp = new Node;
	temp->data = i;
	temp->weight = w;

	current = head;

	if(!head){
		head = temp;
        head->next = NULL;
        tail = head;
    }
	else{
		tail->next = temp;
        tail = tail->next;
        tail->next = NULL;
    }
}


void List::Reset()
{
    current = head;
}


bool List::GetNext()
{
    if(current->next){
        current = current->next;
        return true;
    }
    
    else
        return false;
}


int List::GetData()
{
    return current->data;
}

int List::GetWeight()
{
	return current->weight;
}


void List::Print()
{
    current = head;

    if(head)
    {
    	cout << " -> " << current->data;
    
		while(GetNext())
		{
			cout << " -> " << current->data;
		}
	}
}


bool List::Empty()
{
	if(head)
		return false;

	return true;
}
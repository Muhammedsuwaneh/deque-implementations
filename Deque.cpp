////////////////////////////////////////////////////////////////////////////////////////////
/*
  Algorithms and Data Structures
  Deque Implementations
  Contributors:
  Muhammed Suwaneh - 152120181098
  Department of Computer Engineering
  Eskisehir Osmangazi University, December 2020
  Eskisehir, Turkey
 */
 ////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Deque.h"

///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	this->head = this->tail = NULL;
	this->noOfItems = 0;
} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {

	while (this->head) {

		DequeNode* node = this->head;
		this->head = this->head->next;
		delete node;
	}
} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) {
	
	DequeNode*node = new DequeNode(item);

	if (node == NULL) throw std::exception("Deque::AddFront(): Overflow error");

	else if (this->head == NULL) {

		this->head = this->tail = node;
		this->noOfItems++;
	}

	else {

		head->prev = node;
		node->next = head;
		head = node;
		this->noOfItems++;
	}

} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {

	DequeNode* node = new DequeNode(item);

	if (node == NULL) throw std::exception("Deque::AddRear(): Overflow error");

	if (this->head == NULL) {

		this->head = node;
		this->noOfItems++;
	}

	else {

		tail->next = node;
		node->prev = tail;
		tail = node;
		this->noOfItems++;
	}
} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {

	if (IsEmpty()) throw std::exception("Deque::RemoveFront(): Empty Deque");
	else {

		int item = this->head->item;

		DequeNode* node = this->head;
		this->head = this->head->next;
	    
		if (this->head == NULL)
			this->tail = NULL; 
		else
			head->prev = NULL;

		delete node;
		this->noOfItems--;
		return item;
	}
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	if (IsEmpty()) throw std::exception("Deque::RemoveRear(): Empty Deque");
	else {

		int item = tail->item;
		DequeNode* node = tail;
		tail = tail->prev;

		if (tail == NULL) head = NULL;
		else
			tail->next = NULL;

		delete node;
		this->noOfItems--;
		return item;
	}
} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	
	if (IsEmpty()) throw std::exception("Deque::Front(): Empty Deque");

	else return this->head->item;
	
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {

	if(IsEmpty()) throw std::exception("Deque::Rear(): Empty Deque");
	
	return tail->item;
	
} //end-Rear
 

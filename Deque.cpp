////////////////////////////////////////////////////////////////////////////////////////////
/*
  Algorithms and Data Structures
  Expression Evaluations
  Contributors:
  Muhammed Suwaneh - 152120181098
  Department of Computer Engineering
  Eskisehir Osmangazi University, December 2020
  Eskisehir, Turkey
 */
 ////////////////////////////////////////////////////////////////////////////////////////////

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

	if (this->head == NULL) {

		this->head = node;
		this->noOfItems++;
	}

	else if (this->head->next == NULL) {

		this->tail = this->head;
		this->head = node;
		this->noOfItems++;
	}

} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {

	DequeNode* node, *curr;

	node = new DequeNode(item);

	curr = this->head;

	if (this->head == NULL) {

		this->head = node;
		this->noOfItems++;
	}

	else {

		while (curr->next != NULL) { curr = curr->next; }

		curr->next = node;

		this->noOfItems++;
	}
} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {
	// Fill this in
	return 0;
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	// Fill this in
	return 0;
} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	
	DequeNode* curr = head;

	if (curr == NULL) { return NULL; }

	else return curr->item;
	
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {

	DequeNode* curr;

	curr = head;
	
	if (curr->next == NULL) {

		return curr->item;
	}

	else {

		while (curr->next != NULL) { curr = curr->next; }

		return curr->item;
	}
	
} //end-Rear

#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
* This is a priority queue, which means that as items are removed in order
* of decreasing priority.
*/

template<class Pri, class T>
class Heap : public Queue < std::pair<Pri, T> > {
public:
	Heap();
	~Heap();

	//Add a new item
	virtual void add(std::pair<Pri,T> toAdd);

	//Remove the item with lowest priority, and return it
	//If the queue is empty, throw a string exception
	virtual std::pair<Pri,T> remove();

	//Return the number of items currently in the queue
	virtual unsigned long getNumItems();

private:
	int arrSize;
	int numItems;
	std::pair<Pri, T>* backingArray;

	//Grow the backingArray by making a new array of twice the size,
	// and copying over the data
	void grow();

	//Check the item at index, and make sure it is in the right place.
	// If not, swap it up the "tree" of the heap until you find the right
	// place
	void bubbleUp(unsigned long index);

	//Check the item at index, and make sure it is in the right place.
	// If not, swap it down the "tree" of the heap until you find the right
	// place
	void trickleDown(unsigned long index);  
};


#include <string>

template<class Pri, class T>
Heap<Pri, T>::Heap(){
	arrSize = 10;
	numItems = 0;
	backingArray = new std::pair<Pri, T>[10];
}

template<class Pri, class T>
Heap<Pri, T>::~Heap(){
	arrSize = 0;
	numItems = 0;
	delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri, T>::grow(){
	std::pair<Pri, T>* newbackingArray = new std::pair<Pri, T>[2 * arrSize];

	for (int i = 0; i < numItems; i++){
		newbackingArray[i] = backingArray[i];
	}

	backingArray = newbackingArray;
	delete[] backingArray;
	arrSize *= 2;
}

template<class Pri, class T>
void Heap<Pri, T>::add(std::pair<Pri, T> toAdd){
	//if item is not in heap
	if (numItems + 1 > arrSize){
		grow();
	}
	if (numItems + 1 < arrSize){
		int index = numItems + 1;
		backingArray[index] = toAdd;
		numItems++;
		bubbleUp((index - 1) / 2);
	}
}

template<class Pri, class T>
void Heap<Pri, T>::bubbleUp(unsigned long index){
	std::pair<Pri, T> temp = backingArray[index];

	while (index > 0 && backingArray[(index - 1) / 2] < temp){
		backingArray[index] = backingArray[(index - 1) / 2];

		backingArray[(index - 1) / 2] == temp;

		index = (index - 1) / 2;
	}
}

template<class Pri, class T>
void Heap<Pri, T>::trickleDown(unsigned long index){
	/*while (index >= 0){
	std::pair<Pri, T> leftchild = backingArray[(2 * index) + 1];
	std::pair<Pri, T> rightchild = backingArray[(2 * index) + 2];

	if (leftchild < backingArray[index]){
	backingArray[(2 * index) + 1] = backingArray[index];
	backingArray[index] = leftchild;
	}
	if (rightchild < backingArray[index]){
	backingArray[(2 * index) + 2] = backingArray[index];
	backingArray[index] = rightchild;
	}
	else{
	index = -1;
	}
	index = -1;
	}*/
	do {
		int j = -1;
		int right = (2 * index) + 2;
		if (right < numItems && backingArray[right] < backingArray[index]) {
			int left = (2 * index) + 1;
			if (backingArray[left] < backingArray[right]) {
				j = left;
			} else {
				j = right;
			}
		} else {
			int left = (2 * index) + 1;
			if (left < numItems && backingArray[left] < backingArray[index]) {
				j = left;
			}
		}
		if (j >= 0) {
			backingArray[index] = backingArray[j];
			//backingArray.swap(index, j);
		}
		index = j;
	} while (index >= 0);
}

template<class Pri, class T>
std::pair<Pri, T> Heap<Pri, T>::remove(){
	if (numItems == 0){
		throw std::string("Queue is empty...");
	}

	std::pair<Pri, T> tmp = backingArray[0];
	backingArray[0] == backingArray[numItems - 1];
	numItems--;
	trickleDown(0);
	return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri, T>::getNumItems(){
	return numItems;
}

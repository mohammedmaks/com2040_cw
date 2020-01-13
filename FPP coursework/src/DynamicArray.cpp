/*
 * DynamicArray.cpp
 *
 *  Created on: 9 Jan 2020
 *      Author: mohammedmakama
 */

#include "DynamicArray.h"

// implementation of constructor
template<typename T>
DynamicArray<T>::DynamicArray() {
	this->cap = 5;
	this->noOfElements = 0;
	this->myArray = new T*[this->cap];
	this->initialize();
	cout << "object created\n";

}

//implementation of destrucor
template<typename T>
DynamicArray<T>::~DynamicArray() {
	//loop through array and delete all elements from memory
	for (int i = 0; i < this->cap; i++) {
		delete this->myArray[i];
	}
	delete[] this->myArray;
	cout << "object deleted\n";
}

template<typename T>
void DynamicArray<T>::initialize(int from) {
	//loop through array and initialize all positions to null
	for (int i = from; i < this->cap; i++) {
		this->myArray[i] = nullptr;
	}
}

template<typename T>
void DynamicArray<T>::expand() {
	this->cap += 5;

	T **tempArr = new T*[this->cap];

	for (int i = 0; i < this->noOfElements; i++) {
		tempArr[i] = new T(*this->myArray[i]);
	}

	for (int i = 0; i < this->noOfElements; i++) {
		delete this->myArray[i];
	}
	delete[] this->myArray;

	this->myArray = tempArr;

	this->initialize(this->noOfElements);
}

//Q1.1.c
//returns the number of elements inside the array.
template<typename T>
int DynamicArray<T>::size() {
	return this->noOfElements;
}

//Q1.1.f
//this member function returns the elements inside the array
template<typename T>
void DynamicArray<T>::printElements() {
	//if()
	for (int i = 0; i < this->cap; i++) {
		cout << std::scientific;
		cout << *this->myArray[i] <<" "<< i << "\n";
	}
}

//q1.1.e
template<typename T>
void DynamicArray<T>::add(const T &obj) {
	//if the number of elements in the array is greater than the cap size then expand the array
	if (this->noOfElements > this->cap
			|| (this->noOfElements +1 > this->cap)) {
		this->expand();
	}
	for (size_t i = this->noOfElements; i > 0; i--) {
		myArray[i] = myArray[i - 1];
	}

	this->myArray[0] = new T(obj);
	this->noOfElements++;
}

//Q1.1.d
template<typename T>
T& DynamicArray<T>::operator[](const int index) {
	{
		if (index < 0 || index >= this->noOfElements)
			throw "Bad index!";

		return *this->myArray[index];
	}

}




/*
 * DynamicArray.h
 *
 *  Created on: 24 Dec 2019
 *      Author: mohammedmakama
 */

#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include  <iostream>
using namespace std;
#include <string>

template<class T>
class DynamicArray {

private:
	//Q1.1.a
	//current number of elements
	int noOfElements;
	//current size of the array
	int cap;
	//the array/ the elements of the array
	T **myArray;

public:
	//Q1.1.b
	//constructor
	DynamicArray();
	//copy constructor
	DynamicArray(const DynamicArray &obj);
	//destructor
	~DynamicArray();

	//method to create and initialize the array to a certain size with temporary values.
	void initialize(int from=0);
	//method to expand the array if the capacity is full
	void expand();
	//data specifying the size of the array
	int size();
	// print
	void printElements();
	//T& get(int index);
	//member function to add elements to array
	void add(const T &obj);
	T& operator[](const int index);

};


#endif /* DYNAMICARRAY_H_ */


/*
 * main.cpp
 *
 *  Created on: 9 Jan 2020
 *      Author: mohammedmakama
 */

#include "DynamicArray.cpp"
#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int inputInt=0;
	double inputDouble;
	DynamicArray<int> intArray;
	DynamicArray<double> doubleArray;

	srand(time(0));
	for (int i = 0; i < 5; i++) {
		intArray.add(rand() % 101);
	}

	for (int i = 0; i < 5; i++) {
		doubleArray.add((double) rand() / ((double) RAND_MAX + 1));
	}

	cout << "Input your 5 integer numbers one by one\n ";
	for(int i=0; i<5;i++){
		cout << i+1<<":";
		cin >> inputInt;
		intArray.add(inputInt);
		//cout << endl;
	}

	cout << "Input your 5 double numbers one by one\n ";
		for(int i=0; i<5;i++){
			cout << i+1<<":";
			cin >> inputDouble;
			doubleArray.add(inputDouble);
			//cout << endl;
		}

	cout<< "Elements in the integer array\n";
	intArray.printElements();

	cout<< "Elements in the double array\n";
	doubleArray.printElements();

	//intArray.~DynamicArray();
	doubleArray.~DynamicArray();

	return 0;
}


#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T>
class Vector {
public:
    Vector() {
        elementsCount = 0;
        arraySize = 10;
        elementsArray = new T[arraySize];
    }

    ~Vector() {
        clear();
        delete[] elementsArray;
    }

    void push_back(T item) {
        if(elementsCount==arraySize)
            resize();

        elementsArray[elementsCount] = item;
        elementsCount++;
    }

    void insert(T item, int position) {
        if (position < 0 || position > elementsCount)
            throw out_of_range("Index out of range");

        if(elementsCount==arraySize)
            resize();

        for (int i = elementsCount; i > position; i--) {
            elementsArray[i] = elementsArray[i - 1]; //Moves elements to the right
        }
        elementsArray[position] = item;
        elementsCount++;
    }

    void remove(int position) {
        if (position < 0 || position >= elementsCount)
            throw out_of_range("Index out of range");

        for (int i = position; i < elementsCount - 1; i++) {
            elementsArray[i] = elementsArray[i + 1];
        }
        elementsCount--;
        //cout << "Deleted. New count: " << elementsCount << endl;
    }

    T& operator[](int index) {
        if (index < 0 || index >= elementsCount)
            throw out_of_range("Index out of range");
        return elementsArray[index];
    }

    int size() const {
        return elementsCount;
    }

    void clear() {
        elementsCount = 0;
        //I can rewrite over other values, I don't need to remove them all
    }

private:
    T* elementsArray;
    int arraySize;
    int elementsCount;

    void resize(){
        arraySize += 10;
        T* temp = elementsArray;
        elementsArray = new T[arraySize];
        for(int i = 0; i < elementsCount; i++)
            elementsArray[i] = temp[i];
        delete[] temp;
    }
};
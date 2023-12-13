#pragma once
#include <vector>
using namespace std;

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    int middle = (left + right) / 2;

    if(array[left] > array[middle]){
        swap(array[left], array[middle]);
    }
    if(array[middle] > array[right]){
        swap(array[middle], array[right]);
    }
    if(array[left] > array[middle]){
        swap(array[left], array[middle]);
    }

    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    int middle = medianOfThree(array, left, right);

    T temp = array[left];
    array[left] = array[middle];
    array[middle] = temp;
    T& pivot = array[left];

    int up = left + 1;
    int down = right;

    //Step 4
    /*while(up < down){
        while((array[up] != array[left + 1]) || (up != right))
            up++;
        while(!(array[down] <= pivot) || (down == left))
            down--;
        if(up < down)
            swap(array[left], array[down]);
    }*/

    while (up <= down) {
        while (up <= down && array[up] <= pivot) {
            up++;
        }
        while (array[down] > pivot) {
            down--;
        }
        if (up < down) {
            swap(array[up], array[down]);
        }
    }

    temp = array[left];
    array[left] = array[down];
    array[down] = temp;

    return down; //Pivot index
}

template<class T>
void quickSortHelper(vector<T>& array, int low, int high) {
    if(low > high)
        return;

    int pi = partition(array, low, high);

    quickSortHelper(array, low, pi - 1);
    quickSortHelper(array, pi + 1, high);
}

template<class T>
void sort(std::vector<T>& array) {
    quickSortHelper(array, 0, array.size()-1);
}


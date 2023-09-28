#pragma once
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
class VectorSet {
public:
    bool contains(T item) const {
        // return true if item is in the set and false if not
        return find(t.begin(), t.end(), item) != t.end();
    }

    bool insert(T item) {
        // return true if item is inserted and false if item is already in the set
        if (contains(item)) //Item is already in the set
            return false;
        else{
            t.push_back(item);
            return true;
        }
    }

    bool remove(T item) {
        // return true if item is removed and false if item wasn't in the set
        typename vector<T>::iterator itr = t.begin();
            //Can also use: auto itr = t.begin();

        if(contains(item)){
            for(itr = t.begin(); itr != t.end(); itr++){
                if(*itr == item)
                    t.erase(itr);
            }
            return true;
        }
        else
            return false;
    }

    int size() const {
        // implement size here

        // return the number of items in the set
        return 0;
    }

    bool empty() const {
        // implement empty here

        // return true if the set is empty and return false otherwise
        return true;
    }

    void clear() {
        // implement clear here

        // remove all items from the set
    }

private:
    vector<T> t;

};
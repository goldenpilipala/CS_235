#pragma once

#include <iostream>
using namespace std;

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        //Node(T v) : next(nullptr), value(v) {}
        Node(T v){ //Less efficient constructor
            value = v;
            next = nullptr;
        }
    };

    SLList() {
        head = nullptr;
        tail = nullptr;
        count = 0;

        //cout << "Constructor" << endl;
    }

    ~SLList() {
        //cout << "Destructor" << endl;
        clear();
    }

    const Node* get_head() const {
        // implement get_head here
        return head;
    }

    void push_back(T item) {
        // implement push_back here
        Node* newNode = new Node(item);

        if(head == nullptr){ //If list is empty
            tail = newNode;
            head = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        count++;
    }

    void pop_back() {
        //Empty list
        if(head == nullptr)
            return;

        //One element
        else if(head->next == nullptr){
            delete head;
            head = nullptr;
            tail = nullptr;
        }

        //Normal case
        else{
            Node* itr = head;
            for(int i = 0; i < (size()-1-1); i++)
                itr = itr->next;

            Node* temp = tail;
            itr->next = nullptr;
            delete temp;
            tail = itr;
            count--;
        }
    }

    const T& front() const {
        // implement front here
        return head->value;
    }

    int size() const {
        // implement size here
        return count;
    }

    void clear() {
        // implement clear here
        while(head != nullptr)
            remove(0);
    }

    ///////////////////////////////////

    void print(){
        cout << "Linked list is: ";

        Node* itr = head;
        while(itr != nullptr){
            cout << itr->value << ", ";
            itr = itr->next;
        }
        cout << endl;
    }

    void print(Node *itr){ //Printing recursively
        if(itr != nullptr){
            cout << itr->value << ", ";
            print(itr->next);
        }
    }

    void remove(int position){
        if(position >= size())
            return;

        //Case 1: position = 0
        if(position == 0){
            Node* temp = head;
            head = head->next;
            delete temp; //delete expects a pointer
            count--;
        }

        //Case 2: position = size() - 1
        else if(position == (size()-1)) {
            Node* itr = head;
            for(int i = 0; i < (position-1); i++)
                itr = itr->next;

            Node* temp = tail;
            itr->next = nullptr;
            delete temp;
            tail = itr;
            count--;
        }

        //Case 3: Removing something in the middle
        else{
            Node* itr = head;
            for(int i = 0; i < (position-1); i++)
                itr = itr->next;
            Node* temp = itr->next;
            itr->next = itr->next->next;
            delete temp;
            count--;
        }

    }

private:
    Node* head;
    Node* tail;
    int count; //How many items are in the linked list

};
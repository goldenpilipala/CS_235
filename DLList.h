#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    DLList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~DLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_front(T item) {
        Node* newNode = new Node(item);

        if(head == nullptr){ //If list is empty
            tail = newNode;
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        count++;
    }

    void push_back(T item) {
        Node* newNode = new Node(item);

        if(head == nullptr){ //If list is empty
            tail = newNode;
            head = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        count++;
    }

    void insert(T item, int position) {
        if(size() !=0 && position > size()) //Can add at beginning and end
            throw std::out_of_range("Out of range");
        if(position == 0)
            push_front(item);
        else if(position==size()-1)
            push_back(item);
        else{
            Node* newNode = new Node(item);

            Node* itr = head;
            for(int i = 0; i < (position-1); i++)
                itr = itr->next;

            newNode->prev = itr;
            newNode->next = itr->next;
            itr->next->prev = newNode;
            itr->next = newNode;

            count++;
        }
    }

    void pop_front() {
        if(size()==0)
            throw std::length_error("Length error");
        remove(0);
    }

    void pop_back() {
        if(size()==0)
            throw std::length_error("Length error");
        remove(size()-1);
    }

    void remove(int position) {
        if(position >= size())
            throw std::out_of_range("Out of range");

        //Case 1: position = 0
        if(position == 0){
            Node* temp = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
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

            if (tail->prev != nullptr) {
                tail = tail->prev;  // Update tail to the previous node
                tail->next = nullptr;  // Set the next of the new tail to nullptr
            } else
                head = nullptr;

            delete temp;
            count--;
        }

        //Case 3: Removing something in the middle
        else{
            Node* itr = head;
            for(int i = 0; i < (position); i++)
                itr = itr->next;

            Node* temp = itr;
            itr->prev->next = itr->next; // Update next of the previous node
            if (itr->next != nullptr)
                itr->next->prev = itr->prev; // Update prev of the next node
            delete temp;

            count--;
        }
    }

    const T& front() const {
        if(count==0){
            throw std::out_of_range("List is empty");
        }
        return head->value;
    }
    const T& back() const {
        if(count==0)
            throw std::out_of_range("List is empty");
        return tail->value;
    }
    const T& at(int index) const {
        if(index >= size())
            throw std::out_of_range("Out of range");

        Node* itr = head;
        for(int i = 0; i <= (index-1); i++)
            itr = itr->next;
        return itr->value;
    }

    bool contains(const T& item) const {
        Node* itr = head;
        while(itr != nullptr){
            if(itr-> value == item)
                return true;
            itr = itr->next;
        }
        return false;
    }

    int size() const {
        return count;
    }

    void clear() {
        /*Node* itr = head;
        for(int i = 0; i <= (size()-1); i++) {
            Node* temp = itr;
            remove(0);
            temp = itr->next;
            delete temp;
        }*/
        int sizeValue = size();
        for(int i = 0; i <= (sizeValue-1); i++) {
            Node *temp = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp; //delete expects a pointer
            count--;
        }
    }

    void print(){
        cout << "Linked list is: ";

        Node* itr = head;
        while(itr != nullptr){
            cout << itr->value << " ";
            itr = itr->next;
        }
        cout << endl;
    }

private:
    Node* head;
    Node* tail;
    int count;

};
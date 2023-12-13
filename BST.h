#pragma once

using namespace std;

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    BST() {
        root = nullptr;
        count = 0;
    }

    ~BST() {
        //cout << "Deconstructor" << endl;
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    T getRoot(){
        return root->value;
    }

    bool insert(T item) {
        return insertHelper(root, item);
    }

    bool remove(T item) {
        if(contains(item))
            count--;
        return removeHelper(root, item);
    }

    bool contains(T item) const {
        return containsHelper(root, item);
    }

    void clear() {
        while(size() > 0)
            clearHelper(root);
    }

    int size() const {
        return count;
    }

private:
    Node* root;
    int count;

    void clearHelper(Node*& N){ //Depth-first
        if(N==nullptr) //If Node exists
            return;
        if(N->left == nullptr && N-> right == nullptr){ //Leaf node
            remove(N->value);
            //count--;
        }
        if(N!=nullptr){
            clearHelper(N->left);
            clearHelper(N->right);
        }
    }

    bool insertHelper(Node*& N, T v){
        //&-- so that it refers to the actual BST node and not just a copy
            //that will become obsolete outside of this function

        //Base cases
        if(N==nullptr){ //If reached the end, insert item
            N = new Node(v);
            count++;
            return true;
        }
        if(N->value == v) //Item already in tree
            return false;

        //Recursion
        else if(N->value > v)
            return insertHelper(N->left, v);
        else
            return insertHelper(N->right, v);
    }

    bool removeHelper(Node*& N, T v){
        //Base cases
        if(N==nullptr)
            return false;
        if(!contains(v))
            return false;
        if(N->value == v){ //Remove implemented here
            int childCount = children(N);

            //Removing nodes
            if(childCount == 0)
                removeNodeWithNoChildren(N);
            else if(childCount == 1)
                removeNodeWithOneChild(N);
            else if(childCount == 2)
                removeNodeWithTwoChildren(N);

            //count--; //Can't do this because of recursive call in removeNodeWithTwoChildren()

            return true;
        }

        //Recursion
        else if(N->value > v)
            return removeHelper(N->left, v);
        else
            return removeHelper(N->right, v);
    }

    int children(const Node* N) const {
        int children = 0;
        if(N->left != nullptr)
            children++;
        if(N->right != nullptr)
            children++;

        return children;
    }

    void removeNodeWithNoChildren(Node*& N){
        delete N;
        N = nullptr;
    }
    void removeNodeWithOneChild(Node*& N){
        Node* temp = N; //Access to memory location that needs to be deleted
        if(N->left == nullptr){
            N = N->right;
            delete temp;
        }
        else if(N->right == nullptr){
            N = N->left;
            delete temp;
        }
    }
    void removeNodeWithTwoChildren(Node*& N){
        Node* iop = findIOP(N->left);
        N->value = iop->value;
        removeHelper(N->left, iop->value);
    }

    Node* findIOP(Node* N){
        while (N->right != nullptr)
            N = N->right;
        return N;
    }

    bool containsHelper(const Node* N, T v) const{
        //Base cases
        if(N==nullptr)
            return false;
        if(N->value == v)
            return true;

        //Recursion
        else if(N->value > v)
            return containsHelper(N->left, v);
        else
            return containsHelper(N->right, v);
    }

};
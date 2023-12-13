#pragma once
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

int getHeight(Node* n){
    if(n==nullptr)
        return -1;
    else
        return n->height;
}

void updateHeight(Node* n){
    if (n != nullptr) {
        int hLeft = getHeight(n->left);
        int hRight = getHeight(n->right);
        n->height = (max(hLeft, hRight) + 1);
    }
}

void promote_left(Node*& root) { //rotateRight
    Node* temp = root;
    root = root->left;
    temp->left = root->right;
    root->right = temp;

    updateHeight(temp);
    updateHeight(root);
}

void promote_right(Node*& root) { //rotateLeft
    Node* temp = root;
    root = root->right;
    temp->right = root->left;
    root->left = temp;

    updateHeight(temp);
    updateHeight(root);
}

void rebalance(Node*& root) {
    int hLeft = getHeight(root->left);
    int hRight = getHeight(root->right);

    int hLeftLeft = getHeight(root->left->left);
    int hRightRight = getHeight(root->right->right);
    int hLeftRight = getHeight(root->left->right);
    int hRightLeft = getHeight(root->right->left);

    if(1 >= abs(hLeft - hRight)) {
        if(hLeft > hRight){
            if(hLeftLeft >= hLeftRight) //Left-left imbalance
                promote_left(root);
            else{ //Left-right imbalance
                promote_right(root->left);
                promote_left(root);
            }
        }
        else {
            if(hRightRight >= hRightLeft) //Right-right imbalance
                promote_right(root);
            else{ //Right-left imbalance
                promote_left(root->right);
                promote_right(root);
            }
        }
    }
}


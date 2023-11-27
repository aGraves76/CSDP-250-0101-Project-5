// This is BinarySearchTree.h
// Amanda Graves
// CSDP 250-0101 Project 5
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node*leftNext;
    Node*rightNext;
    
    //constructor
    Node(int value):data(value),leftNext(nullptr),rightNext(nullptr){}
    
    //destructor
    ~Node(){}
};

class BinarySearchTree
{
    public:
        //constructor
        BinarySearchTree() : root(nullptr) {}
        
        //destructor
        ~BinarySearchTree()
        {
            cout<<"Destructor deleting nodes: \n";
            deleteAllNodes(root);
            cout<<endl;
        }
        
        void insert(int vaule);
        void remove(int value);
        void traverse(string type);
        bool isAVLTree() const;
        
    private:
        Node* root;
        
        Node* insertNode(Node*node,int value);
        Node* deleteNode(Node*node,int data);
         Node* getLeftmost(Node* branch) const;
   
        void preOrderTraversal(Node* node) const;
        void inOrderTraversal(Node* node) const;
        void postOrderTraversal(Node* node) const;
    
        bool isAVLTree(const Node* root) const;
        int getBalanceFactor(const Node* node) const;
        int getHeight(const Node* node) const;
    
        void deleteAllNodes(Node* node) const;
};

#endif
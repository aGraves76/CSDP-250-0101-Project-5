// This is BinarySearchTree.cpp
// Amanda Graves
// CSDP 250-0101 Project 5
//

#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

//public functions

void BinarySearchTree::insert(int value)
    {
        root=insertNode(root,value);
    }
    
void BinarySearchTree::remove(int data)
    {
        root=deleteNode(root,data);
        if(root==nullptr)
            cout<<"Node: "<<data<<" not found.\n\n";
        else
            cout<<"Node: "<<data<<" deleted.\n\n";
    }
    
void BinarySearchTree::traverse(string type)
    {
        if (type == "preOrder")
            preOrderTraversal(root);
        else if (type == "postOrder")
            postOrderTraversal(root);
        else  // default to "inOrder"
            inOrderTraversal(root);    
           
        cout << endl << endl;
    }
    
    bool BinarySearchTree::isAVLTree() const
        {
            return isAVLTree(root);
        }

//private functions

//recursively insert nodes
Node*BinarySearchTree::insertNode(Node*node,int value)
    {
        //exit condition
        if(node==nullptr)
            {
                //create new node
                Node*newNode = new Node(value);
                
                return newNode;
            }
        
        //recurse down the tree
        if(value < node->data)
            node->leftNext=insertNode(node->leftNext, value);
        else if (value > node->data)
            node->rightNext = insertNode(node->rightNext, value);
            
        return node;
    }

//recursively locate node to be deleted
Node* BinarySearchTree::deleteNode(Node* nood, int data)
    {
        //exit condition
        if (nood == nullptr)
            return nullptr;
            
        //recursively locate node
        if (data < nood->data)
            nood->leftNext=deleteNode(nood->leftNext, data);
        else if (data > nood->data)
            nood->rightNext = deleteNode(nood->rightNext, data);
   
        // determine node's branches
        else
        {
            // node is leaf (no children)
            if (nood->leftNext == nullptr && nood->rightNext == nullptr)
            {
                delete nood;
                nood = nullptr;
            }
            // node has right child only
            else if (nood->leftNext == nullptr)
            {
                Node* tempNode = nood->rightNext;
                delete nood;
                nood = tempNode;
            }
            // node has left child only
            else if (nood->rightNext == nullptr)
            {
                Node* tempNode = nood->leftNext;
                delete nood;
                nood = tempNode;
            }
            // node has two children
            else
            {
                // replacement has next largest value in the BST
                Node* replacementNode = getLeftmost(nood->rightNext);
                nood->data = replacementNode->data;
                nood->rightNext = deleteNode(nood->rightNext, replacementNode->data);
            }
        }

    return nood;
}

// locate smallest node in branch -- use root for whole BST  
Node* BinarySearchTree::getLeftmost(Node* branch) const
{
    if (branch == nullptr)
        return nullptr;

    while (branch->leftNext != nullptr)
        branch = branch->leftNext;

    return branch;
}
   
// recursive pre-order traversal
void BinarySearchTree::preOrderTraversal(Node* node) const
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        preOrderTraversal(node->leftNext);
        preOrderTraversal(node->rightNext);
    }
}        
   
// recursive in-order traversal
void BinarySearchTree::inOrderTraversal(Node* node) const
{
    if (node != nullptr)
    {
        inOrderTraversal(node->leftNext);
        cout << node->data << " ";
        inOrderTraversal(node->rightNext);
    }
}        
   
// recursive post-order traversal
void BinarySearchTree::postOrderTraversal(Node* node) const
{
    if (node != nullptr)
    {
        postOrderTraversal(node->leftNext);
        postOrderTraversal(node->rightNext);
        cout << node->data << " ";
    }
}        

// recursive AVL Tree test
bool BinarySearchTree::isAVLTree(const Node* trunk) const
{
    // exit condition
    if (trunk == nullptr)
        return true;

    int balanceFactor = getBalanceFactor(trunk);
    if (balanceFactor < -1 || balanceFactor > 1)
        return false;

    return isAVLTree(trunk->leftNext) && isAVLTree(trunk->rightNext);
}

int BinarySearchTree::getBalanceFactor(const Node* node) const
{
    if (node == nullptr)
        return 0;

    return getHeight(node->leftNext) - getHeight(node->rightNext);
}

// recursively get node height
int BinarySearchTree::getHeight(const Node* node) const
{
    // exit condition
    if (node == nullptr)
        return -1;

    return max(getHeight(node->leftNext), getHeight(node->rightNext)) + 1;
}
 
// delete all nodes using in-order traversal
void BinarySearchTree::deleteAllNodes(Node* node) const
{
    if (node != nullptr)
    {
        deleteAllNodes(node->leftNext);
        cout << node->data << " ";
        delete node;
        deleteAllNodes(node->rightNext);
    }
}  
         

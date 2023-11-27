// This is BSTRemoveNode.cpp
// Amanda Graves
// CSDP 250-0101 Project 5
//

#include "BinarySearchTree.h"
#include <iostream>
#include <random>
#include <unordered_set>

using namespace std;

int main()
{
    BinarySearchTree bst;
    unordered_set<int> valSet;
    
    //intial random num generator(rng)
    uniform_int_distribution<int> distro(1,99);
    mt19937 rng(time(nullptr));
    
    //store int into array
    while (valSet.size()<40)
        valSet.insert(distro(rng));
        
    //instert nodes into BST
    cout<<"Unique integers: \n";
    for (int value : valSet)
      {
            bst.insert(value);
            cout<<value<<" ";
      }
    cout<<endl<<endl;
    
    //print node before deletion
    cout<<"Pre delete in-order traversal: \n";
    bst.traverse("inOrder");
    
    //get user input
    bool found=false;
    int choice=0;
    while (!found)
        {
            cout<<"Select a node to delete? ";
            cin>>choice;
            
            //input validation
            if(valSet.find(choice)==valSet.end())
                cout<<"\nNode: "<<choice<<" not found. Try again.\n\n";
            else
               {
                //delete node
                found=true;
                bst.remove(choice);
                valSet.erase(choice);
               }
        }
        
    //print node after deletion
    cout<<"Post delete in-order traversal: \n";
    bst.traverse("inOrder");    
    
    //AVL Test
    if (bst.isAVLTree())
        cout<<"BST is an AVL Tree.\n\n";
    else
        cout<<"BST is NOT an AVL Tree.\n\n";
        
    return 0;
}
  
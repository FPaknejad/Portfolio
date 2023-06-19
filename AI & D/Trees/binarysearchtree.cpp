//Binary Search tree

// when adding a node, if it's greater then it goes to right
// 47 is parent, add 76, goes on right
// add 52, goes to right, but 76 is there, so it goes left of 76
// add 21, left of 47 is open so it goes there
// add 82
// add 18
// 27


//     47
//    /   
//   21   76
//  / \   / 
// 18 27 52 82   

#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BST{
    public:
        Node* root;
    
//alternatively:        
//        BST(int value){
//            Node* newNode = new Node(value);
//            root = newNode;
//        }


        BST(){
            root = nullptr;
        }



};

int main(){
    BST* myBST = new BST();
    cout<<"root: "<<myBST->root<<endl;
}
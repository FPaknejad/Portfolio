#include <iostream>

using namespace std;

class Node {
    public: 
        int value; //node value => member variable
        Node* next; //pointer  that points to node

        Node(int value){
            this ->value = value;
            // this ->next = nullptr; // we don' have next aasa poarameter for Node constructor.
            // so no need to this for pointer, since there is only one?
            next=nullptr; 
            //this points to memeber variable
    //  Node(int val){
    //      value = val;
    //      next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value){
            Node* newNode = new Node(value); 
            // Node* newNode is a variable that can point to a variable
            // New Node(value): new runs constructor
            // Everything on right of == is what creates
            // newNode = Node that points to nullptr
            //equal sign adds a pointer to from newNode
            //      (a node created) to another node with value of "value"
            head = newNode; //head and newNode point to the same node
            tail = newNode;
            length = 1;

    }

        void printList(){
            Node* temp = head; 
            while (temp) { //true as long as temp is pointing at a node>> temp!= nullptr
                cout<< temp->value<<endl; //value of the node temp is point to
                //temp has access to attrubutes value and next
                temp = temp -> next; 
                //last node is nullptr which breaks the loop
            }
        }

        void getHead(){
            cout<<"Head: "<<head->value<<endl;
        }
        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
            }  
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }
};



int main() {
    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->getHead();// -> is used because myLinkedList is declared as a pointer to LinkedList class in the line above
    myLinkedList->getTail();
    myLinkedList->getLength();
}
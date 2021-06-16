#include<iostream>
using namespace std;

class Node{
    
    public: 
        int data;
        Node * next;

        void traverseLinkedList(){
            Node* ptr;
            ptr = this;

            while(ptr != NULL){
                cout << "Element: " << ptr -> data << "\n";
                ptr = ptr -> next;
            }
        }
};



int main(){

    Node* head;
    Node* end;

    head = new Node;
    end = new Node;

    head -> data = 98;
    head -> next = end;

    end -> data = 119;
    end -> next = NULL;

    head -> traverseLinkedList();
 
    return 0;
}
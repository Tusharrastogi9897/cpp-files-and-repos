#include<iostream>
using namespace std;

class Node{
    
    public: 
        int data;
        Node * next;

        void traverseLinkedList(){
            Node* ptr;
            ptr = this;

            cout<<"\n";
            while(ptr != NULL){
                cout << "Element: " << ptr -> data << "\n";
                ptr = ptr -> next;
            }
            cout<<"\n";

        }

        int sizeOf(){
            Node* ptr;
            ptr = this;
            int size = 0;

            while(ptr != NULL){
                size += 1;
                ptr = ptr -> next;
            }
            return size;
        }

        void insert(int pos, int data){
            Node *ptr;
            Node *new_node;

            new_node = new Node;
            ptr = this;

            int size = 0;
            
            if(ptr -> sizeOf() >= pos)
                while(ptr != NULL){
                    if(pos == 0){
                        new_node -> next = ptr -> next;
                        new_node -> data = ptr -> data;
                        this -> data = data;
                        this -> next = new_node;
                        break;
                    }
                    else if(size == (pos - 1)){
                        new_node -> data = data;
                        new_node -> next = ptr -> next;
                        ptr -> next = new_node;
                        break;
                    }
                    size += 1;
                    ptr = ptr -> next;
                }
            else
                cout<<"\nCannot Insert value!!\n";
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
    head -> insert(2, 78);

    cout<<"After insertion:";
    head -> traverseLinkedList();

    return 0;
}
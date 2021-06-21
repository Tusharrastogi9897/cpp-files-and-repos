#include<iostream>
using namespace std;

class Node{
    
    public: 
        int data;
        Node * next;
        Node * prev;

        void traverseLinkedList(){
            Node* ptr;
            ptr = this;

            cout<<"\n";
            while(ptr){
                cout << ptr -> data << " - > ";
                ptr = ptr -> next;
            }
            cout<<"NULL\n\n";

        }

        void traverseFromEnd(){
            Node* ptr;
            ptr = this;

            cout<<"\n";
            while(ptr){
                cout << ptr -> data << " - > ";
                ptr = ptr -> prev;
            }
            cout<<"NULL\n\n";

        }

        int sizeOf(){
            Node* ptr;
            ptr = this;
            int size = 0;

            while(ptr){
                size += 1;
                ptr = ptr -> next;
            }
            return size;
        }

        Node* find(int pos){
            Node* ptr;
            ptr = this;
            int size = 0;

            Node* found;
            found = NULL;

            while(ptr){
                if(pos == size){
                    found = ptr;
                    break;
                }
                size += 1;
                ptr = ptr -> next;
            }

            return found;
        }

        void insert(int pos, int data){
            Node *ptr;
            Node *new_node;

            new_node = new Node;
            ptr = this;

            int size = 0;
            
            if(ptr -> sizeOf() >= pos)
                while(ptr){
                    if(pos == 0){
                        new_node -> next = ptr -> next;
                        new_node -> data = ptr -> data;
                        this -> data = data;
                        this -> next = new_node;
                        this -> prev = NULL;
                        new_node -> prev = this;
                        break;
                    }
                    else if(size == (pos - 1)){
                        new_node -> data = data;
                        new_node -> next = ptr -> next;
                        new_node -> prev = ptr;
                        ptr -> next = new_node;
                        break;
                    }
                    size += 1;
                    ptr = ptr -> next;
                }
            else
                cout<<"\nCannot Insert value!!\n";
        }

        void deleteNode(int pos){
            Node *ptr;
            ptr = this;

            int size = 0;
            
            if(ptr -> sizeOf() > pos){
                while(ptr){
                    if(pos == 0){
                        ptr -> data = ptr -> next -> data;
                        ptr -> next = ptr -> next -> next;
                        ptr -> prev = NULL;
                        break;
                    } 
                    else if((pos - 1) == size){
                        if(ptr -> next)
                            ptr -> next = ptr -> next -> next;
                        else
                            ptr -> next = NULL;
                    }
                    size += 1;
                    ptr = ptr -> next; 
                }
            }
            else
                cout<<"\nIndex does not exist!!\n";
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

    head -> deleteNode(0);

    cout<<"After deletion:";
    head -> traverseLinkedList();

    return 0;
}
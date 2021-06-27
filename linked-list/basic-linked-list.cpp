#include <iostream>
#include "LinkedList.h"

using namespace std;

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
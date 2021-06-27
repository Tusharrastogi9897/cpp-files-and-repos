#include<iostream>

using namespace std;
#define MAX 1000

class Stack{
    
    public: 
        int top {-1};
        int arr[MAX];

        bool isFull(){
            if(this -> top >= MAX - 1)
                return true;
            
            return false;
        }

        bool isEmpty(){
            if(this -> top == -1)
                return true;
            
            return false;
        }

        void push(int val){
            if(this -> isFull())
                cout<<" Stack is Full!! ";
            else{
                this -> arr[this -> top + 1] = val;
                this -> top += 1;
            }
        }

        void pop(){
            if(this -> isFull())
                cout<<" Stack is Empty!! ";
            else{
                this -> arr[this -> top] = 0;
                this -> top -= 1;
            }
        }
};



int main(){

    Stack * stack_;
    stack_ = new Stack;

    stack_ -> push(98);
    stack_ -> push(79);

    cout<<"Current Stack is: \n";
    for (int i = 0; i <= stack_ -> top; i++)
        cout<< stack_ -> arr[i]<< " ";
    cout<<"\n";

    return 0;
}
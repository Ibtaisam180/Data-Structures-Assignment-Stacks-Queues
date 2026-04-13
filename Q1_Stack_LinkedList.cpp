/*
Subject: Data Structures
Course Code: CP233
Student: IBTAISAM ASIF KHAN
Roll No: L1F24BSDS0012
Section: DD-1

Question 1
Stack implementation using singly linked list.
Operations: push, pop, peek, display, isEmpty.
*/
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Stack{
public:
    Node* top;
    Stack(){
        top = NULL;
    }
    bool isEmpty(){
        return (top == NULL);
    }  
    void push(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Element inserted" << endl;
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;
        cout << "Removed element: " << top->data << endl;
        top = top->next;
        delete temp;
    }
    void peek(){
        if(isEmpty())
            cout << "Stack is empty" << endl;
        else
            cout << "Top element: " << top->data << endl;
    }
    void display(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements:" << endl;
        while(temp != NULL){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main(){

    Stack s;
    int choice = 0, value;   
    while(choice != 6){
        cout << endl;
        cout << "1 Push" << endl;
        cout << "2 Pop" << endl;
        cout << "3 Peek" << endl;
        cout << "4 Display" << endl;
        cout << "5 Check Empty" << endl;
        cout << "6 Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            s.display();
        }
        else if(choice == 2){
            s.pop();
            s.display();
        }
    else if(choice == 3){
            s.peek();
        }

        else if(choice == 4){
            s.display();
        }
        else if(choice == 5){
            if(s.isEmpty())
                cout << "Stack is empty" << endl;
            else
                cout << "Stack is not empty" << endl;
        }
        else if(choice == 6){
            cout << "Program ended" << endl;
        }
        else{
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

/*
Question 2
Queue implementation using singly linked list.
Operations: enqueue, dequeue, front element, isEmpty.
FIFO principle.
*/
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Queue{
public:
    Node* front;
    Node* rear;

    Queue(){
        front = NULL;
        rear = NULL;
    }

    bool isEmpty(){
        return (front == NULL);
    }

    void enqueue(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if(isEmpty()){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Element inserted" << endl;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return;
        }

        Node* temp = front;
        cout << "Removed element: " << front->data << endl;

        front = front->next;

        if(front == NULL)
            rear = NULL;

        delete temp;
    }

    void frontElement(){
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else
            cout << "Front element: " << front->data << endl;
    }
};

int main(){

    Queue q;
    int choice = 0, value;

    while(choice != 5){

        cout << endl;
        cout << "1 Enqueue" << endl;
        cout << "2 Dequeue" << endl;
        cout << "3 Front Element" << endl;
        cout << "4 Check Empty" << endl;
        cout << "5 Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
        }

        else if(choice == 2){
            q.dequeue();
        }

        else if(choice == 3){
            q.frontElement();
        }

        else if(choice == 4){
            if(q.isEmpty())
                cout << "Queue is empty" << endl;
            else
                cout << "Queue is not empty" << endl;
        }

        else if(choice == 5){
            cout << "Program ended" << endl;
        }

        else{
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

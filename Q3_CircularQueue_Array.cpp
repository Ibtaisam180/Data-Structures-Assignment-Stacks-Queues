/*
Question 3
Circular Queue implementation using array.
Operations:
enqueue
dequeue
peek
display
isFull
isEmpty
*/
#include <iostream>
using namespace std;

class CircularQueue {
    int arr[5];
    int size;
    int front;
    int rear;

public:
    CircularQueue() {
        size = 5;
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((rear + 1) % size == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } 
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        cout << value << " inserted" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << arr[front] << " removed" << endl;

        if (front == rear) {
            front = rear = -1;
        } 
        else {
            front = (front + 1) % size;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } 
        else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice = 0, value;

    while (choice != 6) {

        cout << endl;
        cout << "1 Enqueue" << endl;
        cout << "2 Dequeue" << endl;
        cout << "3 Peek" << endl;
        cout << "4 Display" << endl;
        cout << "5 Check Empty" << endl;
        cout << "6 Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            q.display();
        }
        else if (choice == 2) {
            q.dequeue();
            q.display();
        }
        else if (choice == 3) {
            q.peek();
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            if (q.isEmpty())
                cout << "Queue is empty" << endl;
            else
                cout << "Queue is not empty" << endl;
        }
        else if (choice == 6) {
            cout << "Program ended" << endl;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

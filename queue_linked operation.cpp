#include <iostream>
using namespace std;

class Node {
public:
    int info;
    Node* next;

    Node(int val) {
        info = val;
        next = nullptr;
    }
};

Node* front;
Node* rear;

bool isEmpty() {
    return front == NULL;
}

void traverse() {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;

    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
    cout << "Front: " << front->info
         << " Rear: " << rear->info << endl;
}

void enqueue(int val) {
    Node* newNode = new Node(val);

    if (front == NULL) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;
    front = front->next;
    delete temp;

    // Important: if the queue becomes empty
    if (front == NULL) {
        rear = NULL;
    }
}

int main() {
    front = rear = NULL;

    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    }

    enqueue(10);
    enqueue(20);

    cout << "Queue elements: ";
    traverse();

    cout << "Dequeue:" << endl;
    dequeue();

    cout << "Queue after dequeue: ";
    traverse();

    return 0;
}
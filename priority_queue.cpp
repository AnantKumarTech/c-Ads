#include <iostream>
#include <queue>
using namespace std;

// Insert elements
void insert(priority_queue<int>& pq) {
    int n, x;

    cout << "How many elements? ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }
}

// Display top element
void showTop(priority_queue<int>& pq) {
    if (pq.empty()) {
        cout << "Priority Queue is empty" << endl;
        return;
    }

    cout << "Top element: " << pq.top() << endl;
}

// Display all elements
void display(priority_queue<int> pq) {

    cout << "Priority Queue: ";

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;
}

// Remove top element
void removeTop(priority_queue<int>& pq) {
    if (pq.empty()) {
        cout << "Priority Queue is empty" << endl;
        return;
    }

    cout << "Removed: " << pq.top() << endl;
    pq.pop();
}

int main() {

    priority_queue<int> pq;

    insert(pq);

    showTop(pq);

    display(pq);

    removeTop(pq);

    showTop(pq);

    display(pq);

    return 0;
}
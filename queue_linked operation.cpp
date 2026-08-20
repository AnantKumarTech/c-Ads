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
Node* front,* rear;
bool isEmpty() {
    return (front == nullptr);
}

int main() {

}
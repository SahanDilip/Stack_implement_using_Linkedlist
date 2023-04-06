#include <iostream>
#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void Push(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void Pop() {
    if(top == nullptr) {
        cout << "Stack is Underflow" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

bool IsEmpty() {
    if (top == nullptr) {
        return true;
    } else {
        return false;
    }
}

int StackTop() {
    if(!IsEmpty()) {
        return top->data;
    } else {
        return -1; // Return -1 for an empty stack
    }
}

void Display() {
    if(top == nullptr) {
        cout << "Stack is Empty" << endl;
        return;
    }
    Node* temp = top;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    auto start = high_resolution_clock::now();
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop(); Pop(); Pop(); Pop(); Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() <<" "<< "microseconds"<<endl;
    return 0;
}


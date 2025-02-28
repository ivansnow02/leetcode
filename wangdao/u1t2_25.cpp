#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void solution(Node *head) {
    auto p = head, q = head;
    Node *r;

    while (q->next != nullptr) {
        p = p->next;
        q = q->next;
        if (q->next != nullptr) {
            q = q->next;
        }
    }
    q = p->next;
    p->next = nullptr;
    while (q != nullptr) {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }

    auto s = head->next;
    q = p->next;
    p->next = nullptr;
    while (q != nullptr) {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
}

// Function to create a linked list
Node* createList(vector<int> values) {
    Node* dummy = new Node{0, nullptr};
    Node* current = dummy;

    for (int val : values) {
        current->next = new Node{val, nullptr};
        current = current->next;
    }

    return dummy;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head->next;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to free memory
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create a sample linked list
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* head = createList(values);

    cout << "Original List: ";
    printList(head);

    // Apply the solution
    solution(head);

    cout << "Modified List: ";
    printList(head);

    // Clean up
    deleteList(head);

    return 0;
}

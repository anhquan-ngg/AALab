#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *makeNode(int val) {
    auto *newNode = new ListNode();
    newNode->val = val;
    newNode->next = nullptr;
    return newNode;
}

void pushBack(ListNode **head, int val) {
    ListNode *newNode = makeNode(val);
    ListNode *tmp = *head;
    if (tmp == nullptr) {
        *head = newNode;
    }
    else {
        while (tmp->next != nullptr) {
            tmp = tmp -> next;
        }
        tmp -> next = newNode;
    }
}

void Traversal(ListNode *head) {
    ListNode *tmp = head;
    while (tmp != nullptr) {
        cout << tmp -> val << " ";
        tmp = tmp -> next;
    }
}

// class Solution {
// public:
//     vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
//
//     }
// };

int main() {

    ListNode *head = makeNode(1);
    pushBack(&head, 2);
    pushBack(&head, 3);
    pushBack(&head, 4);
    pushBack(&head, 5);
    Traversal(head);
    return 0;
}
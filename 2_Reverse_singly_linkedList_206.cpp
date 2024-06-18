#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize pointers
        ListNode *prevnode = nullptr;
        ListNode *currentnode = head;
        ListNode *nextnode = nullptr;

        // Iterate through the list and reverse the links
        while (currentnode != nullptr) {
            nextnode = currentnode->next; // Store the next node
            currentnode->next = prevnode; // Reverse the current node's pointer
            prevnode = currentnode;       // Move the prevnode to the current node
            currentnode = nextnode;       // Move to the next node in the list
        }

        // After the loop, prevnode will be the new head of the reversed list
        return prevnode;
    }
};


int main() {
    // Create a linked list 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    // Reverse the linked list
    Solution solution;
    head = solution.reverseList(head);

    std::cout << "Reversed list: ";
    printList(head);

    return 0;
}

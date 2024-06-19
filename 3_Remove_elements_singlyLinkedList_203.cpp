#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node to simplify edge cases where the head needs to be removed
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* current = head;
        ListNode* prev = temp;

        while (current != nullptr) {
            if (current->val == val) {
                // If the current node needs to be removed
                prev->next = current->next;
                delete current; // Free the memory of the removed node
                current = prev->next; // Move to the next node
            } else {
                // Move both prev and current pointers forward
                prev = current;
                current = current->next;
            }
        }

        // Update head to the new head
        head = temp->next;
        delete temp; // Free the memory of the dummy node
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Main function to test the removeElements method
int main() {
    Solution solution;
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, size);

    std::cout << "Original List: ";
    printList(head);

    int val = 6;
    head = solution.removeElements(head, val);

    std::cout << "Modified List after removing " << val << ": ";
    printList(head);

    // Free the memory of the list
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

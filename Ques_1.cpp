#include <iostream>
using namespace std; 

// Definition for singly-linked list node
struct ListNode {
    int val;          // Value of the node
    ListNode *next;   // Pointer to the next node
    ListNode(int x) : val(x), next(nullptr) {} // Constructor to initialize the node
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr; // 'prev' will be the new head, starting as nullptr
    ListNode* curr = head;    // 'curr' is the current node, starting at the head
    ListNode* next = nullptr; // 'next' will temporarily store the next node

    // Loop through the linked list
    while (curr != nullptr) {
        next = curr->next;    // Save the next node
        curr->next = prev;    // Reverse the current node's pointer
        prev = curr;          // Move 'prev' to 'curr'
        curr = next;          // Move 'curr' to 'next'
    }

    return prev;              // 'prev' is the new head of the reversed list
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;    // Temporary pointer to go through the list
    while (temp != nullptr) {
        cout << temp->val << " "; // Print the value of the current node
        temp = temp->next;    // Move to the next node
    }
    cout << endl;             // Print a new line at the end
}


int main() {
    // Create a simple linked list 1->2->3->4->5
    ListNode* head = new ListNode(1);      // First node with value 1
    head->next = new ListNode(2);          // Second node with value 2
    head->next->next = new ListNode(3);    // Third node with value 3
    head->next->next->next = new ListNode(4); // Fourth node with value 4
    head->next->next->next->next = new ListNode(5); // Fifth node with value 5

    cout << "Original list: ";
    printList(head);  // Print the original list

    // Reverse the linked list
    ListNode* reversedHead = reverseList(head); // Call the reverse function

    cout << "Reversed list: ";
    printList(reversedHead);  // Print the reversed list

    return 0;
}


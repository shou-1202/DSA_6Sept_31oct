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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Dummy node acts as the head of the sorted portion
        ListNode dummy(0); 
        ListNode* curr = head;

        while (curr) {
            // At each iteration, start searching from the beginning of the sorted list
            ListNode* prev = &dummy;

            // Find the correct position to insert the current node
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Store the next node to process
            ListNode* next_node = curr->next;

            // Wire the current node into the sorted portion
            curr->next = prev->next;
            prev->next = curr;

            // Advance to the next unsorted node
            curr = next_node;
        }

        return dummy.next;
    }
};
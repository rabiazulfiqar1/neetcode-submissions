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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev =  NULL;
        ListNode* nextptr = head -> next;
        while (head != NULL) {
            nextptr = head->next;
            head->next = prev;
            prev = head;
            head = nextptr;
        }
        return prev;
    }
};

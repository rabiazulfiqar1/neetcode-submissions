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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* length = head;
        while (length) {
            len++;
            length = length->next;
        }
        int nodes = len-n;
        if (nodes == 0) return head->next;
        ListNode* llist = head;
        ListNode* prev = NULL;
        while (nodes > 0) {
            prev = head;
            head = head->next;
            nodes--;
        }
        prev->next = head->next;
        return llist;
    }
};

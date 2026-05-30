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
    ListNode* getkth(ListNode* h, int k) {
        for (int i=0; i<k; i++) {
            if (h) h = h->next;
            else break;
        }
        return h;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupprev = dummy;

        while (1) {
            ListNode* kth = getkth(groupprev, k);
            if (kth == NULL) break;
            ListNode* nextgroup = kth->next;

            ListNode* prev = kth->next;
            ListNode* curr = groupprev->next;
            ListNode* nextptr = NULL;

            while (curr != nextgroup) {
                nextptr = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextptr;
            }

            ListNode* temp = groupprev->next;
            groupprev->next = kth;
            groupprev = temp;
        }

        return dummy->next;
    }
};

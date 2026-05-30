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
    ListNode* merge2lists(ListNode* h1, ListNode* h2) {
        ListNode* dummy = new ListNode();
        ListNode* merged = dummy;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                merged->next = new ListNode(h1->val);
                h1 = h1->next;
            } else {
                merged->next = new ListNode(h2->val);
                h2 = h2->next;
            }
            merged = merged->next;
        }
        if (h1) {
            merged->next = h1;
        } 
        if (h2) {
            merged->next = h2;
        }
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        if (lists.size() == 1) return lists[0];
        int k = lists.size();
        ListNode* merged = NULL;
        for (int i=1; i<k; i++) {
            merged = merge2lists(lists[i], lists[i-1]);
            lists[i] = merged;
        }
        return merged;
    }
};

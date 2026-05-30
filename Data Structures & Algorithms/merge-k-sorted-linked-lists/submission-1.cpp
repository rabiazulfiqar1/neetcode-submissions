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
                merged->next = h1;
                h1 = h1->next;
            } else {
                merged->next = h2;
                h2 = h2->next;
            }
            merged = merged->next;
        }
        if (h1) {
            merged->next = h1;
        } 
        else if (h2) {
            merged->next = h2;
        }
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        if (lists.size() == 1) return lists[0];
        while (lists.size() > 1) {
            vector<ListNode*> merged; 
            for (int i=0; i<lists.size(); i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i+1] : NULL;
                merged.push_back(merge2lists(l1, l2));
            }
            lists = merged;
        }
        return lists[0];
    }
};

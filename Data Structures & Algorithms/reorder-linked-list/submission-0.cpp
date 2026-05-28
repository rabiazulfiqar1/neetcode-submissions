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
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* ptr2 = slow->next;
        slow->next = NULL;
        ptr2 = reverseList(ptr2);
        ListNode* ptr1 = head;
        while (ptr2) {
            ListNode* tmp1 = ptr1->next;
            ListNode* tmp2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = tmp1;
            ptr1 = tmp1;
            ptr2 = tmp2;
        }
        head = ptr1;
    }
};

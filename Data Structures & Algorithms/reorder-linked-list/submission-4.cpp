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
    void reorderList(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *prev, *curr, *nxt;
        prev = slow;
        nxt = curr = slow->next;
        prev->next = nullptr;

        while (curr) {
            nxt = nxt->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        ListNode *l, *r, *temp;
        l = head;
        r = prev;
        
        while (l != r) {
            temp = l->next;
            l->next = r;
            l = temp;
            temp = r->next;
            if (!temp) break;
            r->next = l;
            r = temp;
        }
    }
};

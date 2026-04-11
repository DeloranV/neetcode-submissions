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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev, *curr, *nxt, *begin, *before_begin;
        prev = nullptr;
        nxt = curr = head;
        int left_cpy = left;
        
        while (left_cpy > 1) {
            nxt = nxt->next;
            prev = curr;
            curr = nxt;
            left_cpy--;
        }
        begin = curr;
        before_begin = prev;

        int reverseTimes = right - left + 1;
        while (curr && reverseTimes > 0) {
            nxt = nxt->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            reverseTimes--;
        }
        begin->next = curr;
        if (before_begin) before_begin->next = prev;
        if (left == 1) head = prev;

        return head;
    }
};
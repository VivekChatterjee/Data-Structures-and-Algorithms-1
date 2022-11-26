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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head, *even = head->next;
        ListNode *full = new ListNode(0);
        ListNode *first = full, *trav = full;
        while(odd)
        {
            trav->next = new ListNode(odd->val);
            trav = trav->next;
            if(odd->next) odd = odd->next->next;
            else odd = odd->next;
        }
        while(even)
        {
            trav->next = new ListNode(even->val);
            trav = trav->next;
            if(even->next) even = even->next->next;
            else even = even->next;
        }
        return first->next;
    }
};
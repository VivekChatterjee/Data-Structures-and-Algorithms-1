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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode(5);
        ListNode* head = cur;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                head->next = l1;
                l1=l1->next;
            }
            else
            {
                head->next = l2;
                l2=l2->next;
            }
            head=head->next;
        }
        if(l1) head->next=l1;
        if(l2) head->next=l2;
        return cur->next;
    }
};
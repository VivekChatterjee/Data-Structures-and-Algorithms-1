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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head,*fast=head;
        ListNode* beforeMid;
        if(!head || head->next == NULL)
            return NULL;
        while(fast && fast->next)
        {
            beforeMid = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        beforeMid->next = beforeMid->next->next;
        return head;
    }
};
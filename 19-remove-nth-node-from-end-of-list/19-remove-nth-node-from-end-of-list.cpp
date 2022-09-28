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
        int len=0;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            len++;
            cur=cur->next;
        }
        int toDel = len-n;
        if(toDel==0)
            return head->next;
        toDel--;
        cur=head;
        int i=0;
        while(cur!=NULL)
        {
            if(i==toDel)
            {
                if(cur->next->next)
                cur->next=cur->next->next;
                else
                cur->next=NULL;
                
                break;
            }
            i++;
            cur=cur->next;
        }
        return head;
    }
};
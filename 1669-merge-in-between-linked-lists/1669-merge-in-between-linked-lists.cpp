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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first, *sec, *head = list1;
        for(int i=0; i<=b; i++)
        {
            if(i == a-1)
                first = list1;
            if(i == b)
                sec = list1->next;
            list1 = list1->next;
        }
        first->next = list2;
        while(list2)
        {
            if(!list2->next)
            {
                list2->next = sec;
                break;
            }
            list2 = list2->next;
        }
        return head;
    }
};
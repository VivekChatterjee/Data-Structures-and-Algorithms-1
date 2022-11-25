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
    ListNode* nodeValue(ListNode* head, int &sum)
    {
        while(head && head->val != 0)
        {
            sum+=head->val;
            head = head->next;
        }
        return head;
    }
    ListNode* mergeNodes(ListNode* head) {
        ListNode* nodes = new ListNode(0);
        ListNode *root = nodes;
        head = head->next;
        while(head)
        {
            int sum = 0;
            head = nodeValue(head, sum) -> next;
            nodes->val = sum;
            if(head != NULL)
            {
                nodes->next = new ListNode(0);
                nodes = nodes->next;
            }
        }
        return root;        
    }
};
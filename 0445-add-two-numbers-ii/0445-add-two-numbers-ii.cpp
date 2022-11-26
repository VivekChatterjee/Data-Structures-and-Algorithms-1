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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1, s2, st;
        while(l1)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        ListNode* nums = new ListNode(0);
        int carry = 0;
        while(!s1.empty() || !s2.empty())
        {
            int num = 0;
            if(!s1.empty())
            {
                num+=s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                num+=s2.top();
                s2.pop();
            }
            num+=carry;
            carry=0;
            if(num>=10)
            {
                num = num%10;
                carry=1;
            }
            st.push(num);
        }
        if(carry) st.push(carry);
        ListNode* add = new ListNode(0), *head = add;
        while(!st.empty())
        {
            add->next = new ListNode(st.top());
            add = add->next;
            st.pop();
        }
        return head->next;
    }
};

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v;
        while(head)
        {
            v.push_back(head->val);
            head=head->next;
        }
        vector<int>ans;
        stack<int>s;
        for(int i=v.size()-1; i>=0; i--)
        {
            while(!s.empty() && s.top() <= v[i])
                s.pop();
            (s.empty())? ans.push_back(0) : ans.push_back(s.top());
            s.push(v[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
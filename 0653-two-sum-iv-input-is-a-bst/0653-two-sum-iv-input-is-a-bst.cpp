/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator{
    stack<TreeNode*>s;
    // reverse = true = next()
    // reverse = false = before()
    bool reverse = false;
public:
    BSTIterator(TreeNode* root, bool rev)
    {
        reverse = rev;
        pushAll(root);
    }
    
    int nextOrBefore()
    {
        TreeNode* top = s.top();
        s.pop();
        if(reverse) pushAll(top->right);
        else pushAll(top->left);
        return top->val;
    }
    
    bool hasNext()
    {
        return !s.empty();
    }

private:
    void pushAll(TreeNode* root)
    {
        while(root)
        {
            s.push(root);
            if(reverse) root=root->left;
            else root=root->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return 0;
        BSTIterator nxt(root, true);
        BSTIterator b4(root, false);
        // takes the next element, smallest element
        int i = nxt.nextOrBefore();
        // takes the before element, largest element
        int j = b4.nextOrBefore();
        while(i<j)
        {
            if(i+j == k) return 1;
            else if(i+j < k) i = nxt.nextOrBefore();
            else j = b4.nextOrBefore();
        }
        return 0;
    }
};
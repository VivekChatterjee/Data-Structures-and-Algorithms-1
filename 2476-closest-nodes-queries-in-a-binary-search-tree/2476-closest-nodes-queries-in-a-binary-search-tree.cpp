// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int mini=INT_MIN, maxi=INT_MAX;
//     void close(TreeNode* root, int q)
//     {
//         if(root == NULL) return;
//         if(root->val <= q)
//         {
//             mini = max(mini, root->val);
//             close(root->right, q);
//         }
//         if(root->val >= q)
//         {
//             maxi = min(maxi, root->val);
//             close(root->left, q);
//         }
//     }
//     vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
//         vector<vector<int>>ans;
//         for(int i:queries)
//         {
//             close(root, i);
//             if(mini == INT_MIN) mini = -1;
//             if(maxi == INT_MAX) maxi = -1;
//             ans.push_back({mini, maxi});
//             mini=INT_MIN, maxi=INT_MAX;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> search(TreeNode *root , int q){
        TreeNode* p = root;
        int lb = INT_MIN ;
        int ub =  INT_MAX;
        while(p){
            if(p->val > q){
				// update ub since it can be minimum value greater than the key
                ub = min(ub , p->val);
                p =p->left;
            }else if(p->val < q){
				// update ub since it can be minimum value greater than the key
                lb = max(lb , p->val);
                p=p->right;   
			//if found immediately return 
            }else{
                return {p->val , p->val};
            }
        }
        // check if we could not find the bounds
        if(lb == INT_MIN) lb = -1;
        if(ub == INT_MAX) ub = -1;
        return {lb , ub};
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> x(queries.size());
        int i = 0;
        for(int q : queries){
            x[i++] = search(root , q);
        }
        return x;
    }
};
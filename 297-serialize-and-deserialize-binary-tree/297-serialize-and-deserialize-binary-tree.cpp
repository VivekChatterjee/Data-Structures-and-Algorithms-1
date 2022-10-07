/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root == NULL) return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node==NULL) s+="#,";
                else s+=to_string(node->val)+',';
                if(node!=NULL)
                {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return s;
    }

    
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                // left element
                getline(s, str, ',');
                if(str=="#")
                    node->left=NULL;
                else
                {
                    node->left = new TreeNode(stoi(str));
                    q.push(node->left);
                }
                
                // right
                getline(s, str, ',');
                if(str=="#")
                    node->right=NULL;
                else
                {
                    node->right = new TreeNode(stoi(str));
                    q.push(node->right);
                }
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
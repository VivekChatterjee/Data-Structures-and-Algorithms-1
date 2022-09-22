class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>preXor;
        preXor.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
            preXor.push_back(arr[i]^preXor[i-1]);        
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int left=queries[i][0];
            int right=queries[i][1];
            int tillRight;
            tillRight= (left==0)? preXor[right] : preXor[right]^preXor[left-1];
            
            // for(int i=0;i<left;i++)
            //     tillRight^=arr[i];
            ans.push_back(tillRight);
        }
        return ans;
    }
};
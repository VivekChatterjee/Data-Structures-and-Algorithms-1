class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        if(n==1) return {strs};
        unordered_map<string,vector<string>>m;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++)
        {
            string a=strs[i];
            sort(a.begin(),a.end());
            m[a].push_back(strs[i]);
        }
        for(auto i:m)
            ans.push_back(i.second);
        return ans;
    }
};
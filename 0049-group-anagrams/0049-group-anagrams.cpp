class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        if(n==1) return {strs};
        map<string,vector<int>>m;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++)
        {
            string a=strs[i];
            sort(a.begin(),a.end());
            m[a].push_back(i);
        }
        for(auto i:m)
        {
            vector<string>vec;
            for(auto j:i.second)
            {
                vec.push_back(strs[j]);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
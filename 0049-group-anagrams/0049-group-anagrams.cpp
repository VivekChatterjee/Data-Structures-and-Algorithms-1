class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        
        vector<vector<string>>vec;
        
        
        if(n==1)
        {
            vector<string>v;
            v.push_back(strs[0]);
            vec.push_back(v);
            return vec;
        }
        
        else
        {
        vector<pair<string,int>>v;
        for(int i=0;i<n;i++)
        {
            string a=strs[i];
            sort(a.begin(),a.end());
            v.push_back(make_pair(a,i));
        }
        
        sort(v.begin(),v.end());
        

        
        vector<string>s;
        s.push_back(strs[v[0].second]);
        for(int i=1;i<n;i++)
        {
            if(v[i].first == v[i-1].first)
            {
                s.push_back(strs[v[i].second]);
            }
            else
            {
                vec.push_back(s);
                s.clear();
                
                s.push_back(strs[v[i].second]);
            }
        }
            
            if(s.size()>0)
                vec.push_back(s);
            
            return vec;
        }    
    }
};
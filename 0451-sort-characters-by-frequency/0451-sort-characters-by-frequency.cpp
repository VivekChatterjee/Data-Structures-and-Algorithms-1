class Solution {
public:
    static bool mycomp(pair<int, char>a, pair<int, char>b)
    {
        // if(a.first>=b.first)
        //     return true;
        // return false;
        
        return a.first > b.first;
    }
    string frequencySort(string s) {
        unordered_map<char, int>freq;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
        }
        vector<pair<int, char>>ele;
        for(auto x: freq)
        {
            char ch = x.first;
            int times = x.second;
            ele.push_back({times, ch});
        }
        sort(ele.begin(), ele.end(),mycomp);
        string ans = "";
        for(auto x: ele)
        {
            int times = x.first;
            while(times--)
            {
                ans+=x.second;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string sortVowels(string s) {
        string ans=s;
        unordered_map<int, int>m;
        vector<int>v;
        vector<char>vowel={'A','E','I','O','U','a','e','i','o','u'};
        for(int i=0; i<s.size(); i++)
        {
            if(find(vowel.begin(), vowel.end(), s[i]) != vowel.end())
            {
                m[i]++;
                v.push_back((int)s[i]);
            }
        }
        sort(v.begin(), v.end());
        int k=0;
        for(int i=0; i<s.size(); i++)
        {
            if(m.count(i))
            {
                ans[i]=(char)v[k++];
            }
        }
        return ans;
    }
};
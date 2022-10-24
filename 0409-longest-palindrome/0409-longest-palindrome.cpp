class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        
        if(n==1)
            return 1;
        
        int freq[128]={};
        for(auto c:s) 
            freq[c]++;
        
        int odd = 0;
        
        for(auto i:freq) 
            odd += (i & 1);
        
        return s.size() - odd + (odd > 0);  
        
    }
};
class Solution {
public:
    string reverseVowels(string s) {
        string vowels="";
        for(char c:s)
        {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') vowels+=c;
        }
        reverse(vowels.begin(), vowels.end());
        int start=0;
        for(int i=0; i<s.size(); i++)
        {
            char c=s[i];
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') s[i]=vowels[start++];
        }
        return s;
    }
};
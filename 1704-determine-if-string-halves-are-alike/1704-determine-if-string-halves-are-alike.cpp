class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int vowels = 0;
        for(char c: s)
        {
            c = toupper(c);
            if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') vowels++;
        }
        int cur = 0;
        for(int i=0; i<n/2; i++)
        {
            char c = s[i];
            c = toupper(c);
            if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') cur++;
        }
        if(cur == vowels-cur) return 1;
        return 0;
    }
};
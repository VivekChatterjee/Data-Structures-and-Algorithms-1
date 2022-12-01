class Solution {
public:
    void vowel(int i, int n, string &s, int &cur)
    {
        if(i == n) return;
        char c = s[i];
        c = toupper(c);
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') cur+=1;
        vowel(i+1, n, s, cur);
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int firstHalf = 0, secondHalf = 0;
        vowel(0, n/2, s, firstHalf);
        vowel(n/2, n, s, secondHalf);
        if(firstHalf == secondHalf) return 1;
        else return 0;
    }
};
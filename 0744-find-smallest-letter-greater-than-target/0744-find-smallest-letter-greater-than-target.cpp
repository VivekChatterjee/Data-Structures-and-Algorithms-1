class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=(char)123;
        for(char c: letters)
        {
            if(c>target) ans=min(ans, c);
        }
        return (ans == (char)123) ? letters[0] : ans;
    }
};
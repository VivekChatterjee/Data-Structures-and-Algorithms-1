class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans='}';
        for(char c: letters)
        {
            if(c>target) ans=min(ans, c);
        }
        return (ans == '}')? letters[0] : ans;
    }
};
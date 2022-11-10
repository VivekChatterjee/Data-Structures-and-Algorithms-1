class Solution {
public:
    // a to z = 97 to  122
    // A to Z = 65 to 90
    // string makeGood(string s) {
    //     int n=s.size();
    //     for(int i=0; i<n-1; i++)
    //     {
    //         if(s[i]>=97)
    //         {
    //             if(s[i]-'a' == s[i+1]-'A')
    //             {
    //                 s.erase(s.begin()+i);
    //                 s.erase(s.begin()+i);
    //                 if(i!=0) i-=2;
    //                 else i--;
    //             }
    //         }
    //         else
    //         {
    //             if(s[i]-'A' == s[i+1]-'a')
    //             {
    //                 s.erase(s.begin()+i);
    //                 s.erase(s.begin()+i);
    //                 if(i!=0) i-=2;
    //                 else i--;
    //             }
    //         }
    //     }
    //     return s;
    string makeGood(string s) {
        int i=0;
        // s.size() here returns an unsigned value (size_t) so when s.size() becomes 1 s.size()-1 becomes -1 and -1 in unsigned becomes a very large value so the loop continues to run
        int n=s.size();
        while(i<n-1) 
        {
            if(abs(s[i+1]-s[i]) == 32)
            {
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                if(i!=0)
                   i--;
            }
            else i++;
        }
        return s;
    }
};
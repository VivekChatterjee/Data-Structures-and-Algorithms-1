class Solution {
public:
int myAtoi(string s) {
int i=0;
int sign=1;
for (;i<s.size();i++) {
if(s[i] != ' ') break;
}

    if (s[i]=='-') {
        sign=-1;
        i++;
    } else
    if (s[i]=='+') {i++;}

    long long num=0;
    for (;i<s.size();i++) {
        if (s[i]<'0' || s[i]>'9') break;
        auto n = 10*num + s[i]-'0';
        n*=sign;
        if (n < std::numeric_limits<int>::min()) return std::numeric_limits<int>::min();
        if (n > std::numeric_limits<int>::max()) return std::numeric_limits<int>::max();
        num = n*sign;
    }
    return num*sign;
}
};
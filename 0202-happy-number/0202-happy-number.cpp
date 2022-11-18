#define ll long long int
class Solution {
public:
    ll sum(int n)
    {
        ll num = n;
        ll s=0;
        while(num>0)
        {
            ll r=num%10;
            num=num/10;
            s+=r*r;
        }
        return s;
    }
    bool isHappy(int n) {
        unordered_map<ll,int>m;
        ll s = sum(n);
        while(s != 1)
        {
            if(m.count(s)) return 0;
            m[s]++;
            s=sum(s);
        }
        return 1;
    }
};
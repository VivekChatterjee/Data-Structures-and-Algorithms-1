#define ll long long int
class Solution {
public:
    int nthUglyNumber(int n) {
        set<ll>s;
        s.insert(1);
        auto it = s.begin(); 
        for(int i=0; i<n; i++)
        {
            ll number = *it;
            s.insert(number*2);
            s.insert(number*3);
            s.insert(number*5);
            it++;
        }
        it = s.begin();
        advance(it, n-1);
        return *it;
    }
};
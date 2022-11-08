#define ll long long int
#define pp pair<int,int>
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        priority_queue<int, vector<int>, greater<int>>p1, p2;
        int i=0, j=n-1, ct=0;
        ll ans=0;
        while(k--)
        {
            while(p1.size()<candidates && i<=j) p1.push(costs[i++]);
            while(p2.size()<candidates && j>=i) p2.push(costs[j--]);
            int left = (p1.size() > 0)? p1.top() : INT_MAX;
            int right = (p2.size() > 0)? p2.top() : INT_MAX;
            if(left <= right)
            {
                ans+=left;
                p1.pop();
            }
            else
            {
                ans+=right;
                p2.pop();
            }
        }
        return ans;        
    }
};
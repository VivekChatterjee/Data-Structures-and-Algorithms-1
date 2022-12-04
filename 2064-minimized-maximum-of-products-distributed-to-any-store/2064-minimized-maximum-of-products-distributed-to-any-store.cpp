class Solution {
public:
    bool isValid(int cur, int stores, vector<int>& q)
    {
        int count = 0;
        for(int i = 0; i < q.size(); i++)
        {
            if(q[i] <= cur)
                count++;
            else
            {
                int store = q[i];
                while(store > 0)
                {
                    store -= cur;
                    count++;
                }
            }
            if(count > stores) return 0;
        }
        return 1;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int maxi = INT_MIN, size = q.size();
        int low = 1;
        for(int i: q)
        {
            maxi = max(maxi, i);
        }
        int high = maxi, ans=INT_MAX;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(isValid(mid, n, q))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
class Solution {
public:
    int isValid(int cur, int balls, vector<int>& pos)
    {
        int ball = 1, prevBall = 0, n = pos.size();
        for(int i=1; i<n; i++)
        {
            if(pos[i] - pos[prevBall] >= cur)
            {
                ball++;
                prevBall = i;
            }
            if(ball == balls) return 1;
        }
        return 0;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int n = pos.size();
        int mini = pos[0], maxi = pos[n-1];
        int low = 1, high = maxi-mini, ans=INT_MAX;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(isValid(mid, m, pos))
            {
                ans = mid;
                low = mid+1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
class Solution {
public:
    int minCost(string colors, vector<int>& v) {
        int count=0;
        int n=colors.size();
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            if(i!=n-1 && colors[i]==colors[i+1])
            {
                maxi=max(maxi,max(v[i],v[i+1]));
            }
            else
            {
                maxi=max(maxi,v[i]);
                count+=(sum-maxi);
                sum=0;
                maxi=0;
            }
        }
        
        return count;
    }
};
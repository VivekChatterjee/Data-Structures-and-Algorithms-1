class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int maxEnd = 0;
        int s=0;
        int e=0;
        
        for(int i=0;i<nums.size();i++)
        {
            maxEnd+=nums[i];
            
            if(maxEnd>res)
            {
                res=maxEnd;
                e=i;
            }
            
            if(maxEnd<0)
            {
                maxEnd=0;
                s=i+1;
            }
        }
        
        //for length
        // cout<<(e-s+1)<<endl;
        
        return res;
        
    }
};
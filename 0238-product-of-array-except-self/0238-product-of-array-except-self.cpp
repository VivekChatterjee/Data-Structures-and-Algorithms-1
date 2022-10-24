class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {        
        int ct=0;
        int product=1;
        int num;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
                product*=nums[i];
            
            if(nums[i]==0)
            {
                ct++;
                num=i;             
            }
        }
        vector<int>v;
        if(ct==0)
        {
            for(int i:nums)
            {
                v.push_back(product/i);
            }
        }
        
        else
        {
            if(ct>1)
            {   
            for(int i=0;i<nums.size();i++)
            {
                    v.push_back(0);
            }
            }
            
            else
            {
                for(int i=0;i<nums.size();i++)
                {
                    if(nums[i]==0)
                        v.push_back(product);
                    
                    else
                        v.push_back(0);
                }
            }
        }
        
        return v;
    }
};
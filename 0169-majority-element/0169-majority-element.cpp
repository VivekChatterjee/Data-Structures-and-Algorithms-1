class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num=nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count == 0)
                num=nums[i];
            
            if(nums[i] == num)
            {
                count+=1;
            }
            else
            {
                count-=1;
            }
        }
        return num;
    }
};
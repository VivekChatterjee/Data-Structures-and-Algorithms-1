class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == num)
                count+=1;
            else
                count-=1;
            if(count == 0)
            {
                num=nums[i];
                count=1;
            }
        }
        return num;
    }
};
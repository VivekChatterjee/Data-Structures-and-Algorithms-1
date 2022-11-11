class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, n = nums.size();
        int num = -101;
        int j=0;
        while(i<n)
        {
            if(nums[i]!=num)
            {
                nums[j++]=nums[i];
                num=nums[i];
            }
            i++;
        }
        return j;        
    }
};
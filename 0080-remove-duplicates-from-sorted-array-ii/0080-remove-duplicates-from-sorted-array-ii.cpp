class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, n=nums.size(), j=0, num = -1e5, count = 0;
        while(i < n)
        {
            if(nums[i] != num)
            {
                nums[j++] = nums[i];
                num = nums[i];
                count = 1;
            }
            else if(nums[i] == num && count < 2)
            {
                nums[j++] = nums[i];
                num = nums[i];
                count++;
            }
            i++;
        }
        return j;
    }
};
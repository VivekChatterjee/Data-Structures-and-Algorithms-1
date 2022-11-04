class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int smallerInd = -1;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                smallerInd = i;
                break;
            }
        }
        if(smallerInd != -1)
        { 
            for(int i=n-1; i>smallerInd; i--)
            {
                if(nums[i] > nums[smallerInd])
                {
                    swap(nums[i], nums[smallerInd]);
                    break;
                }
            }
            reverse(nums.begin()+smallerInd+1, nums.end());
        }
        else reverse(nums.begin(), nums.end());
    }
};
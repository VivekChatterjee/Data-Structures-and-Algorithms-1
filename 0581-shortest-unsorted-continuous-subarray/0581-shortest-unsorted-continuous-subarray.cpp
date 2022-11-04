class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>sorted=nums;
        sort(sorted.begin(), sorted.end());
        if(nums == sorted) return 0;
        int start=0,end=0;
        bool started=false;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != sorted[i])
            {
                if(!started)
                {
                    started=true;
                    start=i;
                }
                end=i;
            }
        }
        return end-start+1;
    }
};
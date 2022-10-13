// #define vc vector
// class Solution {
// public:
//     vc<vc<int>>ans;
//     void solve(vc<int>&nums, int freq[] , vc<int>v)
//     {
//         if(v.size() == nums.size())
//         {
//             ans.push_back(v);
//             return;
//         }
//         for(int i=0;i<nums.size();i++)
//         {
//             if(!freq[i])
//             {
//                 freq[i]=1;
//                 v.push_back(nums[i]);
//                 solve(nums,freq,v);
//                 v.pop_back();
//                 freq[i]=0;
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vc<int>v;
//         int freq[6]={0};
//         solve(nums,freq,v);
//         return ans;
//     }
// };


// 2nd approach
#define vc vector
class Solution {
public:
    vc<vc<int>>ans;
    void solve(vc<int>&nums, int ind)
    {
        if(ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[i], nums[ind]);
            solve(nums,ind+1);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vc<int>v;
        solve(nums,0);
        return ans;
    }
};
class Solution {
public:
const long long int K =  10e9+7;
    
//     int ways(int n, int k, int sum, int &target)
//     {
//         if(sum > target )
//             return 0;
//         if(n == 0)
//         {
//             if(sum == target)
//                 return 1;
//             else
//                 return 0;
//         }
//         int count=0;
//         for(int i=1;i<=k;i++)
//         {
//             count+=(ways(n-1,i,sum+i,target) % K);
//         }     
//         return count%K;
//     }
    
//     int numRollsToTarget(int n, int k, int target) {
//         return ways(n,k,0,target);
//     }
    
int dp[31][1001] = {};
int numRollsToTarget(int d, int f, int target, int res = 0) {
  if (d == 0 || target <= 0) return d == target;
  if (dp[d][target]) return dp[d][target] - 1;
  for (auto i = 1; i <= f; ++i)
    res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
  dp[d][target] = res + 1;
  return res;
}
};
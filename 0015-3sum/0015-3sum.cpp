class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>v;
        set<vector<int>>ss;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        int num=nums[0];
        
        for(int i=0;i<n-1;i++)
        {
            int s=i+1, e=n-1;
            
            if(i!=0)
                {
                    if(nums[i]==num)
                        continue;
                    
                    num=nums[i];
                }
            
            
            while(s<e)
            {
                int sum=nums[i]+nums[s]+nums[e];
                
                if(sum == 0)
                {
                    vector<int>t(3);
                    t[0]=nums[i];
                    t[1]=nums[s];
                    t[2]=nums[e];
                    
                    if(ss.find(t)==ss.end())
                    {
                    v.push_back(t);
                    ss.insert(t);
                    }
                    
                    s++;
                    e--;
                }
                
                else if(sum > 0)
                    e--;
                
                else
                    s++;
                
            }
            
        }
        
        return v;
    }
};










// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
        
//         sort(nums.begin(),nums.end());
        
//         vector<vector<int>>v;
//         set<vector<int>>s;
        
//         int n=nums.size();
        
//             int num=nums[0];
//             for(int i=0;i<n-1;i++)
//             {
//                 int start = i+1;
//                 int end = n-1;
//                 int k = -(nums[i]);
                
//                 if(i!=0)
//                 {
//                     if(nums[i]==num)
//                         continue;
                    
//                     num=nums[i];
//                 }
                
//                 while(start < end)
//                 {
//                     int sum = nums[start]+nums[end];
                    
//                      if(sum == k)
//                      {
//                          vector<int>t(3);
//                          t[0]=nums[i];
//                          t[1]=nums[start];
//                          t[2]=nums[end];
                         
//                          if(s.find(t) == s.end())
//                          {
//                              v.push_back(t);
//                              s.insert(t);
//                          }
                         
//                          start++;
//                          end--;
//                      }
                    
//                     else if(sum<k)
//                         start++;
                    
//                     else
//                         end--;
                    
//                 }
//             }
            
//             return v;
//     }
// };


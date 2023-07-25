class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        
        int s=0,e=n-1;
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            
            if(mid>=1 && mid<=n-2)
            {
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
                
                else if(arr[mid]>arr[mid-1] && arr[mid+1]>arr[mid])
                s=mid+1;
                
                else
                e=mid-1;                
            }
            
            else
            {
                if(mid==0)
                {
                    if(arr[mid]>arr[mid+1])
                    return mid;
                    
                    else
                    s=mid+1;
                }
                
                else
                {
                    if(arr[mid-1]<arr[mid])
                    return mid;
                    
                    else
                    e=mid-1;
                }
            }
        }
        
        return -1;
    }
};
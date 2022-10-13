//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

#define vc vector
class Solution
{
public:
    vc<int>ans;
    void solve(vector<int> &arr, int n, int i, int sum)
    {
        if(i==n)
        {
            ans.push_back(sum);
            return;
        }
        // don't pick the element
        solve(arr,n,i+1,sum);
        
        // pick the element
        solve(arr,n,i+1,sum+arr[i]);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        sort(arr.begin(),arr.end());
        solve(arr, n, 0, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
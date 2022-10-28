//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#define ll long long int

class Solution {
	public:
	const int K=1e9+7;
		int NthTerm(int n){
		    // Code  here
		    vector<ll>v;
		    v.push_back(2);
		    for(ll i=1;i<=n;i++)
		    {
		        ll num =( (i+1) * (v[i-1]) % K) % K;
		        v.push_back(num+1 % K);
		    }
		    return v[n-1];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
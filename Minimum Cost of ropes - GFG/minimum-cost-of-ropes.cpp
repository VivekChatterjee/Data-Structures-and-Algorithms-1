//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long int
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<ll, vector<ll>, greater<ll>>p;
        for(ll i=0; i<n; i++) p.push(arr[i]);
        ll total = 0;
        while(p.size() > 1)
        {
            ll first = p.top();
            p.pop();
            ll second = p.top();
            p.pop();
            total+=first+second;
            p.push(first + second);
        }
        return total;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
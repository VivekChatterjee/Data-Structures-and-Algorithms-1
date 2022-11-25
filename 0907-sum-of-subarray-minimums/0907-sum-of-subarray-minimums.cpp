class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
     
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> s;
        
        for(int i = 0; i < n; i++) {
            while(s.size() && arr[i] < arr[s.top()]) {
                s.pop();
            }
            
            if(s.size()) {
                left[i] = i - s.top();
            }
            else {
                left[i] = i + 1;
            }
            s.push(i);
        }
        
        while(s.size()) s.pop();
        
        for(int i = n-1; i >= 0; i--) {
            while(s.size() && arr[i] <= arr[s.top()]) {
                s.pop();
            }
            
            if(s.size()) {
                right[i] = s.top() - i;
            }
            else {
                right[i] = n - i;
            }
            s.push(i);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            long long total = (left[i] * right[i]) % mod;
            total = (total * arr[i]) % mod;
            ans = (ans + total) % mod;
        }
        
        return ans;      
    }
};
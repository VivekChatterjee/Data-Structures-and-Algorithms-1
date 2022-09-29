#define pp pair<int,int>
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // using max heap
        // priority_queue<pair<int,int>>p; // condition(|a-x|) , number itself is stored
        // for(int i=0;i<arr.size();i++)
        // {
        //     p.push({abs(x-arr[i]), arr[i]});
        //     if(p.size()>k)
        //         p.pop();
        // }
        // vector<int>ans;
        // while(p.size()>0)
        // {
        //     ans.push_back(p.top().second);
        //     p.pop();
        // }
        // sort(ans.begin(),ans.end());
        
        // using min heap
        priority_queue<pp,vector<pp>, greater<pp>>p; // condition(|a-x|) , number itself is stored
        
        for(int i=0;i<arr.size();i++)
        {
            p.push({abs(x-arr[i]), arr[i]});
        }
        vector<int>ans;
        while(p.size()>(arr.size()-k))
        {
            ans.push_back(p.top().second);
            p.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
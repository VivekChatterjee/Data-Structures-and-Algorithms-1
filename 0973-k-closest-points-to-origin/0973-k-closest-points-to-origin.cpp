#define pp pair<double,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp> p;
        for(int i=0;i <points.size(); i++)
        {
            int f=points[i][0];
            int l=points[i][1];
            double d = sqrt(f*f + l*l);
            p.push({d, {f,l}});
            if(p.size()>k) p.pop();
        }
        vector<vector<int>>ans;
        while(!p.empty())
        {
            pair<double,pair<int,int>> a = p.top();
            ans.push_back({a.second.first, a.second.second});
            p.pop();
        }
        return ans;
    }
};
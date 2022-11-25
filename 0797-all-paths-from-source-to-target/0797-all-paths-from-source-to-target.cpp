class Solution {
public:
    void allPaths(int row, vector<vector<int>>& graph, vector<int> v, vector<vector<int>>& ans)
    {
        int n = graph.size();
        for(auto i: graph[row])
        {
            v.push_back(i);
            if(i == n-1) ans.push_back(v);
            allPaths(i, graph, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>v(1, 0);
        allPaths(0, graph, v, ans);
        return ans;
    }
};
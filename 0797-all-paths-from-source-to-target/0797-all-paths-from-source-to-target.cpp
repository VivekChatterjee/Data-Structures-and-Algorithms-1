class Solution {
public:
    void allPaths(int row, vector<vector<int>>& graph, vector<int> v, vector<vector<int>>& ans)
    {
        v.push_back(row);
        int n = graph.size();
        if(row == n-1) ans.push_back(v);
        else for(auto cur: graph[row]) allPaths(cur, graph, v, ans);
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>v;
        allPaths(0, graph, v, ans);
        return ans;
    }
};
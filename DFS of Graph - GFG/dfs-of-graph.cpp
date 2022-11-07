//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void dfs(int i, vector<int>adj[], vector<int>&vis, vector<int>&ans)
    {
        for(auto j: adj[i])
        {
            if(!vis[j])
            {
                ans.push_back(j);
                vis[j]=1;
                dfs(j, adj, vis, ans);
            }
        }
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int>vis(v+1);
        vector<int>ans(1);
        vis[0]=1;
        dfs(0, adj, vis, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
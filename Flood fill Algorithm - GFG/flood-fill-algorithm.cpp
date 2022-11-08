//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int curColor, color;
        void dfs(vector<vector<int>>& image, vector<vector<int>>& vis, int i, int j)
        {
            int m=image.size();
            int n=image[0].size();
            if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || image[i][j]!=curColor) return;
            vis[i][j]=1;
            image[i][j]=color;
            dfs(image, vis, i-1, j);
            dfs(image, vis, i+1,j);
            dfs(image, vis, i, j-1);
            dfs(image, vis, i, j+1);
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int clr)         {
            int m=image.size();
            int n=image[0].size();
            vector<vector<int>>vis(m, vector<int>(n));
            color=clr;
            curColor=image[sr][sc];
            if(image[sr][sc]!=color && !vis[sr][sc])
            dfs(image, vis, sr, sc);
            return image;
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
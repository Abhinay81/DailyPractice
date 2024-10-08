//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,vector<pair<int,int>> &rt){
        vis[row][col] = 1;
        int n = grid.size(),m = grid[0].size();
        int si = row,sc = col;
        queue<pair<int,int>> q;
        int vr[] = {-1,0,0,1};
        int vc[] = {0,-1,1,0};
        q.push({row,col});
        rt.push_back({si-row,sc-col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+vr[i];
                int nc = c+vc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    rt.push_back({si-nr,sc-nc});
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(),m = grid[0].size();
        set<vector<pair<int,int>>> res;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    vector<pair<int,int>> rt;
                    bfs(i,j,grid,vis,rt);
                    res.insert(rt);
                    
                }
            }
        }
        return res.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> res(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int vr[] = {-1,0,0,1};
        int vc[] = {0,-1,1,0};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int md = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+vr[i];
                int nc = c+vc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    res[nr][nc] = md+1;
                    q.push({{nr,nc},md+1});
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
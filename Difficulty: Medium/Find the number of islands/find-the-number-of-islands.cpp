//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(vector<vector<char>>&grid,int i,int j,int n,int m){
    //   base case
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='0') return;
    
    // visit the current node
    grid[i][j]='0';
    // visit all the  8 neighbours
    for(int a=-1;a<2;a++){
        for(int b=-1;b<2;b++){
            if(!(a==0 && b==0)) dfs(grid,i+a,b+j,n,m);
        }
    }
   }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
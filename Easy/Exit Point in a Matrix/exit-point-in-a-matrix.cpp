//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        int i=0,j=0;
        vector<int> res(2,0);
        //0->right, 1->down, 2->left, 3->up
        int move=0;
        while(i>=0 && j>=0 && i<n && j<m){
            res[0]=i, res[1]=j;
            if(matrix[i][j]==1){
                matrix[i][j]=0;
                move=(move+1)%4;
            }
            switch(move){
                case 0:
                j++; break;
                
                case 1:
                i++; break;
                
                case 2:
                j--; break;
                
                case 3:
                i--; break;
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
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        int ans = 0;
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
            }
            else{
                dp[i][i+1] = 0;
            }
        }
        for(int l = 3;l<=n;l++){
            for(int i=0;i+l-1 < n;i++){
                int st = i;
                int en = i+l-1;
                if(s[st] == s[en]){
                    dp[st][en] = dp[st+1][en-1];
                }
                else{
                    dp[st][en] = 0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans += dp[i][j];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
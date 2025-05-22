class Solution {
  public:
    int minDeletions(string s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
       //dp[i][j] --> minimum number of deletions to make substring(i...j) palindrome 
     //for length 2 strings
        for(int i = 1;i<n;i++)
        {
            if(s[i] != s[i-1])
            {
                dp[i-1][i] = 1;
            }
        }
        ///for length  >2 strings...
       for(int len = 3;len <=n;len++)
       {
           for(int i = 0;i<n-len+1;i++)
           {
               int j = i + len - 1;
               if(s[i] == s[j])
               {
                   dp[i][j] = dp[i+1][j-1];
               }
               else
               {
                   int ans = min({dp[i+1][j]+1,dp[i][j-1]+1,dp[i+1][j-1]+2});
                   dp[i][j] = ans;
               }
           }
       }
       
       return dp[0][n-1];
    }
};
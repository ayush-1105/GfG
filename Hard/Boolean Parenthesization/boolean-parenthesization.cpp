//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    int f(int i, int j, int TF, string& s, vector<vector<vector<int>>>& dp){
        if(i==j){
            if(s[i]=='T' && TF == 0) return 1;
            else if(s[i] == 'F' && TF == 1) return 1;
            else return 0;
        }
        if(dp[i][j][TF]!=-1) return dp[i][j][TF];
        int count = 0;
        for(int idx = i+1; idx<j; idx+=2){
            int lt = f(i,idx-1,0,s,dp), rt = f(idx+1,j,0,s,dp);
            int lf = f(i,idx-1,1,s,dp), rf = f(idx+1,j,1,s,dp);
            if(s[idx]=='&'){
                if(TF == 0){
                    count = (count + lt*rt)%mod;
                }else{
                    count = (count + lt*rf%mod + lf*rt%mod + lf*rf%mod)%mod;
                }
            }else if(s[idx] =='|'){
                if(TF == 0){
                    count = (count + lt*rf%mod + lf*rt%mod + lt*rt%mod)%mod;
                }else{
                    count = (count + lf*rf)%mod;
                }
                
            }else{
                if(TF==0){
                    count = (count + lt*rf%mod + lf*rt%mod)%mod;
                }else{
                    count = (count +lt*rt%mod + lf*rf%mod)%mod; 
                }
            }
        }
        return dp[i][j][TF] = count;
    }
    int countWays(int n, string s){
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,n-1,0,s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
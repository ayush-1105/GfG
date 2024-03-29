//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int sequence(int it , int n , int m){
        if(n==0)return 1;
        if(it > m)return 0;
        if(dp[it][n] != -1)return dp[it][n];
        return dp[it][n] =   sequence(it*2 , n-1 , m) + sequence(it+1 , n , m);
    }
    int numberSequence(int m, int n){
        // code here
         dp = vector<vector<int>>(m+1 , vector<int>(n+1 , -1));
        return sequence(1, n ,m);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
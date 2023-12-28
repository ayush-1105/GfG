//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.size(), i = 0, j = 0, m = pattern.size();
        if((n==1) && (m==1))    return ((wild[0] == pattern[0]) || (wild[0] == '?') || (wild[0] == '*'));
        
        while(((i < n) && (j < m)) && (wild[i] != '*')){
            if((wild[i] != '?') && (wild[i] != pattern[j])) return false;
            ++i, ++j;
        }
        
        if(i == n){
            if(j == m)    return true;
            return false;
        }
        
        if(j == m)  while(i < n)    if(wild[i++] != '*')    return false;
        return (match(wild.substr(i+1), pattern.substr(j)) || match(wild.substr(i), pattern.substr(j+1)));
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends
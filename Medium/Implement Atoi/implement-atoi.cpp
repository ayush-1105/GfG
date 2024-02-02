//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans = 0;
        if(s[0] == '-'){
            for(int idx = 1; idx < s.size();idx++){
                if(!(s[idx] >= '0' && s[idx] <= '9'))
                 return -1;
                 else{
                     ans = ans * 10 + s[idx] - '0';
                 }
                  
            }
            return -ans;
        }
        else{
            for(int idx = 0 ; idx < s.size();idx++){
                 if(!(s[idx] >= '0' && s[idx] <= '9'))
                  return -1;
                 else{
                     ans = ans * 10 + s[idx] - '0';
                 }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
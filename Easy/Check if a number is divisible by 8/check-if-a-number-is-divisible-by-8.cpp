//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string S){
        //code here
        if(S.size()==1 && (S[0]-'0')<8)
            return -1;
            
        int i=0,carry=0, num=0;
        if(S[i]-'0'<8){
            num=(S[i]-'0')*10+S[i+1];
            i=i+2;
        }
        else{
            num=S[i]-'0';
            i++;
        }
        
        while(i<=S.size())
        {
            carry = num%8;
            num=10*carry+S[i];
            i++;
        }
        
        if(carry==0)
            return 1;
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends
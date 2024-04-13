//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        long long msb=1;
        long long lsb=1;
        for(int i=0;i<32;i++){
            msb<<=1;
       }
       while(lsb!=msb){
           if(((msb & x)==msb) && ((lsb & x)!=lsb)){
               x=x &(~msb);
               x=x | lsb;
           }
           else if(((msb & x)!=msb) && ((lsb & x)==lsb)){
               x=x | msb;
               x=x & (~lsb);
           }
           msb>>=1;
           lsb<<=1;
       }
       return x>>1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
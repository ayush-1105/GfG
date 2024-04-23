//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  const int MOD = 1e9 + 7;
    int firstElement(int n) {
        // code here
        int a00 = 1, a01 = 1, a10 = 1, a11 = 0;
        
        for(int i = 1; i<n; i++){
            int prevA00 = a00;
            int prevA10 = a10;
            a00 = (a00 * 1 + a01 * 1) % MOD;
            a01 = prevA00;
            a10 = a01;
            a11 = prevA10;
        }
        
        return a10;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
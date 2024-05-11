//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        // Initialize a vector to store the sequence
        vector<long long> ans;
        
        // Iterate until n becomes 1
        while(n != 1) {
            // Add the current number to the sequence
            ans.push_back(n);
            
            // If n is even, apply the juggler formula with exponent 0.5
            if(n % 2 == 0)
                n = floor(pow(n, 0.5));
            // If n is odd, apply the juggler formula with exponent 1.5
            else
                n = floor(pow(n, 1.5));
        }
        
        // Add 1 to the sequence (final term)
        ans.push_back(1);
        
        // Return the generated sequence
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
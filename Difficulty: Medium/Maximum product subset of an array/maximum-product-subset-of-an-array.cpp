//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        vector<int>negatives;
      long long int mod = 1e9+7;
      long long int ans = 1;
      for(int i = 0; i<arr.size(); i++){
          if(arr[i]>0){
              ans = (ans*arr[i])%mod;
          }
          else if(arr[i]<0){
              negatives.push_back(arr[i]);
          }
      }
      int n = negatives.size();
      int start = 0;
      if(n%2!=0){
         n--;
      }
      sort(negatives.begin(), negatives.end());
      for(int i = start; i<n; i++){
          ans = (ans*negatives[i])%mod;
      }
      return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
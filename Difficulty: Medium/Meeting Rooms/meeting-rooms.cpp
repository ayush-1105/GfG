//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        int maxi = 0;
        for (auto it : arr) {
            maxi = max(maxi, it[1]);
        }
        
        int* freq = new int[maxi + 1]();
        for (auto it : arr) {
            freq[it[0]]++;
            freq[it[1]]--;
        }
        
        for (int i = 1; i <= maxi; i++) {
            freq[i] += freq[i - 1];
            if (freq[i] > 1) {
                delete[] freq;
                return false;
            }
        }
        
        delete[] freq;
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
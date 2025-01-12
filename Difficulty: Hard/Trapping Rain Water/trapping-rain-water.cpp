//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>lft(n, arr[0]), rgt(n, arr[n-1]);
        
        for(int i=1; i<n; i++){
            lft[i]=max(lft[i-1], arr[i]);
        }
        
        for(int i=n-2; i>=0; i--){
            rgt[i]=max(rgt[i+1], arr[i]);
        }
        
        int ans=0;
        
        for(int i=0; i<n; i++){
            ans+=(min(lft[i], rgt[i])-arr[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
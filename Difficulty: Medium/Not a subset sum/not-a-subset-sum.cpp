//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        int sum=0;
        int n=arr.size();
        sum+=arr[0];
        if(arr[0]!=1){
            return 1;
        }
        for(int i=1;i<n;i++){
            if(sum+1 >= arr[i]){
                sum+=arr[i];
            }else{
               return sum+1;
            }
    
        }
        return sum+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        auto ans = ob.findSmallest(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
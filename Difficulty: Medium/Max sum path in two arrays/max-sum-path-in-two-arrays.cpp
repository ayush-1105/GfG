//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int a=0, b=0;
        int n=arr1.size(), m=arr2.size();
        int i=n-1, j=m-1;
        while(i>=0 && j>=0){
            if(arr1[i]>arr2[j]){
                a+=arr1[i];
                i--;
            }else if(arr1[i]<arr2[j]){
                b+=arr2[j];
                j--;
            }else{
                a = max(a,b) + arr1[i];
                b = a;
                i--;
                j--;
            }
        }
        while(i>=0){
            a+=arr1[i];
            i--;
        }
        while(j>=0){
            b+=arr2[j];
            j--;
        }
        return max(a,b);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
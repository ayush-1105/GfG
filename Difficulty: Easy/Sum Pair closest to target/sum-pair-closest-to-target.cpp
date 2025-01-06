//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int maxi = INT_MAX;
        int s = 0;
        int e = n-1;
        int md = -1;
        vector<int> a;
        
        while(s<e)
        {
            int sum = arr[s] + arr[e];
            
            if(abs(target - sum) < abs(target-maxi) || 
            (abs(target - sum) == abs(target-maxi) 
            && (arr[e] - arr[s] > md)))
            {
                maxi = sum;
                md = arr[e] - arr[s];
                a = {arr[s],arr[e]};
                
            }
            
            if(sum < target)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        
        return a;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
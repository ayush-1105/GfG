//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        vector<int> temp;
    for (char c : s) {
        temp.push_back(c - '0');
    }
    int cnt = 0;
    for (int i = 0; cnt < k && i < temp.size(); i++) {
        int fn = temp[i];
        int maxDigit = fn;
        int maxIdx = i;
        for (int j = temp.size() - 1; j > i; j--) {
            if (temp[j] > maxDigit) {
                maxDigit = temp[j];
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(temp[i], temp[maxIdx]);
            cnt++;
        }
    }
    // Convert back to string
    string result = "";
    for (int digit : temp)
        result += to_string(digit);
    return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
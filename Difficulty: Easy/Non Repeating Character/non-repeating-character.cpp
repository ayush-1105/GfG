//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        int ans = INT_MAX;
        map<char,pair<int,int>> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].first = i;
            mp[s[i]].second++;
        }
        
        for(auto m : mp){
            if (m.second.second == 1){
                ans = min(ans,m.second.first);
            }
        }
        return ans  == INT_MAX ? '$':s[ans];
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        vector<int> LPS(str.size(),0);
        int length = 0;
        LPS[0] = 0;
        
        for(int i=1;i<str.size();){
            if(str[i] == str[length]){
                length++;
                LPS[i] = length;
                i++;
            }
            else{
                if(length != 0){
                    length = LPS[length-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        return LPS[str.size()-1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends
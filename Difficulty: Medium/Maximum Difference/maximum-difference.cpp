//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        
        vector<int> left_stack({0}) , right_stack({0});
        vector<int> left_smaller(n,0), right_smaller(n,0);
        
        int out = 0;
        
        for(int i=0; i<n; i++)
        {
            /* fill up the left-smaller array. */
            while(arr[i] <= left_stack.back())
            {
                left_stack.pop_back();
            }
            
            left_smaller[i] = left_stack.back();
            left_stack.push_back(arr[i]);
            
            
            /* fill up the right smaller array. */
            while(arr[n-1-i] <= right_stack.back())
            {
                right_stack.pop_back();
            }
            
            right_smaller[n-1-i] = right_stack.back();
            right_stack.push_back(arr[n-1-i]);
            
        }
        
        for(int i=0; i<n; i++)
        {
            /* calculate the output. */
            out = (abs(left_smaller[i] - right_smaller[i])) > out ? (abs(left_smaller[i] - right_smaller[i])) : out;
        }
        
        return out;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string input;
        getline(cin, input);
        stringstream s2(input);

        vector<int> arr;
        int num;

        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        long long sum1=0,sum2=0;
        for(int i=0; i<n; i++) sum1+=a[i];
        for(int j=0; j<m; j++) sum2+=b[j];
        
        if((sum1+sum2)%2) return -1;
        sort(a, a+n);
        sort(b, b+m);
        
        long long val = abs(sum1-sum2)/2;
        int i=0, j=0;
        while(i<n && j<m){
            long long temp = abs(a[i]-b[j]);
            if(temp==val){
                return 1;
            } 
            else if(temp<val){
                if(a[i]<b[j]) j++;
                else i++;
            }
            else{
                if(a[i]<b[j]) i++;
                else j++;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
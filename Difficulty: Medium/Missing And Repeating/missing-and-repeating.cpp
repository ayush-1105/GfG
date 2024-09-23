//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int rep=0;
        long long n=arr.size();
        long long sa=0;
        for(int i=0;i<n;i++)sa+=arr[i];
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]<0){rep=abs(arr[i]);break;}
            else{arr[abs(arr[i])-1]*=-1;}
        }
        sa-=rep;
        long long sn=(n*(n+1))/2;
        int m=sn-sa;
        return {rep,m};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
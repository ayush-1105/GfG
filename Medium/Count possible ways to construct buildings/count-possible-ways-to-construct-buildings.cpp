//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	#define ll long long int
	const int m = 1e9+7;
	int TotalWays(int n)
	{
	    // Code here
	   vector<ll>zero(n+1);
	    vector<ll>one(n+1);
	    zero[1] = one[1] = 1;
	    for(int i = 2; i<=n; i++){
	        zero[i] = zero[i - 1] + one[i - 1];
	        zero[i] %= m;
	        one[i] = zero[i - 1];
	    }
	    ll val = zero[n] + one[n];
	    val %= m;
	    val = val * val;
	    val %= m;
	    return (int) val;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
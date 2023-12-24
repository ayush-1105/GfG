//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int, int>> v(n);
        // Data structuring: Pairing each stock price with its index
    for (int i = 0; i < n; i++) {
        v[i] = {price[i], i + 1};
    }

    // Sorting stocks based on prices in ascending order
    sort(v.begin(), v.end());

    int ans = 0;

    // Iterating through each day
    for (int i = 0; i < n; i++) {
        // Calculating the maximum stocks that can be purchased on the current day
        int can_purchase = min(v[i].second, k / v[i].first);

        // Updating budget based on stocks purchased
        k -= can_purchase * v[i].first;

        // Accumulating the total number of stocks purchased
        ans += can_purchase;
    }

    return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
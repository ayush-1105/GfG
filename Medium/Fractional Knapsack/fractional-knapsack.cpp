//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>>sack;
        for(int obj = 0; obj < n ; obj++){
            double val = double(arr[obj].value)/ double(arr[obj].weight);
            sack.push_back({val,obj});
        }
        sort(sack.begin(),sack.end(),greater<pair<double,int>>());
        int netWeight = W;
        double profit = 0,idx = 0;
        while( idx < n && arr[sack[idx].second].weight <= netWeight ){
          profit += arr[sack[idx].second].value;
          netWeight -= arr[sack[idx].second].weight;
          idx++;
        }
        if( idx < n && arr[sack[idx].second].weight > netWeight)
         profit += sack[idx].first * netWeight ;
        
        return profit;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
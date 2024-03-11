//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    unordered_set<int>s;
	    
	    //populating the set with elements of matrix1
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            s.insert(mat1[i][j]);
	        }
	    }
	    
	    int count = 0;
	    
	    //traverse matrix 2 and check if (x-b) exists in the set i.e. in matrix1 
	    //If it does, then we will increment the count by 1.
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
                if(s.find(x-mat2[i][j])!=s.end()) count++;
	        }
	    }
	    
	    return count;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends
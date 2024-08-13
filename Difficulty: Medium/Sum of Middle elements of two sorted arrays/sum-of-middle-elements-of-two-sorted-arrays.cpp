//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
         int ans = 0,count=0;
        int n1 = arr1.size(),n2 = arr2.size();
        
        if(arr1[n1-1]<=arr2[0])
        {
            return arr1[n1-1]+arr2[0];
        }
        else if(arr2[n2-1]<=arr1[0])
        {
            return arr2[n2-1]+arr1[0];
        }
        int ts = n1+n2;
        int i=0,j=0,mid1=0,mid2=0;
        
        while(i < n1 && j < n2) 
        {
            if(arr1[i] < arr2[j]) 
            {
                if(count == ts / 2 - 1) mid1 = arr1[i];
                if(count == ts / 2) mid2 = arr1[i];
                i++;
            } 
            else 
            {
                if(count == ts / 2 - 1) mid1 = arr2[j];
                if (count == ts / 2) mid2 = arr2[j];
                j++;
            }
            count++;
        }
        return mid1+mid2; 
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends
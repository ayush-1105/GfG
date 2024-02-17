//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
         queue<int>q;
        q.push(arr[0]);
        int i=0;
        while(i<n/2&&!q.empty()){
            int p=q.front();
            q.pop();
            int c1=2*i+1;
            int c2=2*i+2;
            if(p<arr[c1]||p<arr[c2])
            return false;
            q.push(arr[c1]);
            q.push(arr[c2]);
            i++;
            
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends
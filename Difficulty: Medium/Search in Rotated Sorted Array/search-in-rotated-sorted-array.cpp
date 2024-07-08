//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int lo = 0;
        int hi = arr.size() - 1;
        
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            
            if(arr[mid] == key){
                return mid;
            }
            if(arr[lo] <= arr[mid]){
                if(arr[lo] <= key && arr[mid] > key){
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
            }
            else{
                if(arr[hi] >= key && arr[mid] < key){
                    lo = mid + 1;
                }else{
                    hi = mid - 1;
                }
            }
        }
        return -1;
        // for(int i=0; i<arr.size(); i++){
        //     if(arr[i] == key){
        //         return i;
        //     }
        // }
        // return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        long long  arr[26];
		arr[1]=10;
		arr[2]=36;
		arr[3]=138;
		arr[4]=532;
		arr[5]=2062;
		arr[6]=7990;
		arr[7]=30984;
		arr[8]=120130;
		arr[9]=465832;
		arr[10]=1806282;
		arr[11]=7004156;
		arr[12]=27159440;
		arr[13]=105314726;
		arr[14]=408372232;
		arr[15]=1583522062;
		arr[16]=6140331048l;
		arr[17]=23810014914l;
		arr[18]=92326741146l;
		arr[19]=358010205124l;
		arr[20]=1388236003974l;
		arr[21]=5383084783260l;
		arr[22]=20873685652654l;
		arr[23]=80940720225920l;
		arr[24]=313859293028612l;
		arr[25]=1217034591721250l;
		return arr[n];
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<int> v;
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;

        for (int i = 0; i < N; i++) {
            pq.push({{F[i], S[i]}, i});
        }

        int lastFinishTime = pq.top().first.first;
        v.push_back(pq.top().second + 1); // +1 for 1-based indexing
        pq.pop();

        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            if (t.first.second > lastFinishTime) {
                lastFinishTime = t.first.first;
                v.push_back(t.second + 1); // +1 for 1-based indexing
            }
        }

        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
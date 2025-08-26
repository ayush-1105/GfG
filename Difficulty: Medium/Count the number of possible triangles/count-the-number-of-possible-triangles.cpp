class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int n=arr.size();
        int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                int sum=arr[i]+arr[j];
                int index = std::lower_bound(arr.begin(), arr.end(), sum) - arr.begin();
                if(index==-1)
                    index=n-1;
                if(index-1>j){
                    //cout<<index-1<<endl;
                    //cout<<"sum="<<sum<<" "<<((index-1)-j)<<endl;
                    ans+=((index-1)-j);
                }
            }
        }
        return ans;
    }
};

class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        if(k == s.size())
            return 0;
        unordered_map<char,int> mp;
        priority_queue<int> pq;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        for(auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            pq.push(itr->second);
        }
        
        
        while(k>0 and pq.size())
        {
            int temp = pq.top();
            pq.pop();
            temp--;
            if(temp > 0)
                pq.push(temp);
            k--;
        }
        int ans = 0;
        while(pq.size())
        {
            int temp = pq.top();
            pq.pop();
            ans += temp*temp;
        }
        return ans;
    }
};
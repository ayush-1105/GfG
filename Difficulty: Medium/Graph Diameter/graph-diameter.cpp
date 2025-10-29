class Solution {
  public:
    virtual int giveDist(int i, int V, vector<vector<int>> &adj){
        vector<bool> visited(V, false);
        queue<pair<int, int>> q;
        q.push({i, 0});
        visited[i] = true;
        
        int ans = 0;
        
        while(!q.empty()){
          auto z = q.front();
          q.pop();
          int x = z.first;
          int cost = z.second;
          ans = max(ans, cost);
          
          for(int m: adj[x]){
             if(!visited[m]){
                 visited[m] = true;
                 q.push({m, cost+1});
             } 
          }
          
        }
        return ans;
    }
    
    virtual int giveValue(int i, int V, vector<vector<int>> &adj){
        vector<bool> visited(V, false);
        queue<pair<int, int>> q;
        q.push({i, 0});
        visited[i] = true;
        
        int ans = 0;
        int ii = i;
        
        while(!q.empty()){
          auto z = q.front();
          q.pop();
          int x = z.first;
          int cost = z.second;
          if(cost > ans){
              ans = cost;
              ii = x;
          }
          
          for(int m: adj[x]){
             if(!visited[m]){
                 visited[m] = true;
                 q.push({m, cost+1});
             } 
          }
          
        }
        return ii;
    }
    
    virtual int diameter(int V, vector<vector<int>>& edges) {
       vector<int> indeg(V, 0);
       vector<vector<int>> adj(V);
       int ans = INT_MIN;
       for(auto z: edges){
           adj[z[0]].push_back(z[1]);
           adj[z[1]].push_back(z[0]);
           indeg[z[0]]++;
           indeg[z[1]]++;
           
       }
       
       int mini = INT_MAX;
       for(int x: indeg)
         mini = min(mini, x);
        
        
        // for(int i=0;i<V;i++){
        //   if(indeg[i] == mini)
        //     ans = max(ans, giveDist(i, V, adj));
        // } 
        
        
        
        //good selection procedure
        int ii = giveValue(0, V, adj);
        ans = max(ans, giveDist(ii, V, adj));
        
        
       return ans;
    }
};

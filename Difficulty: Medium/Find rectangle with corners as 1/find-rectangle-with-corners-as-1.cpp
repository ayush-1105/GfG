class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        unordered_set<string>st;
        for(int i =0;i<mat.size();i++){
           vector<int>vec;
           for(int j=0;j<mat[0].size();j++){
               if(mat[i][j]==1)vec.push_back(j);
           }
           
           for(int a= 0;a<vec.size();a++){
               for(int b=a+1;b<vec.size();b++){
                   string s= to_string(vec[a])+"_"+to_string(vec[b]);
                   if(st.find(s)!=st.end())return true;
                 st.insert(s);  
               }
           }
            
        }
     return false;
    }
};
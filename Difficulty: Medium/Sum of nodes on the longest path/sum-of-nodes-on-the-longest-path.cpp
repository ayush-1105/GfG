/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
   

pair<int,int> height(Node* root)
  {
      if(!root) return {0,0};
      if(!root->left && !root->right) return {1,root->data};
      auto left=height(root->left);
      auto right=height(root->right);
      if(left.first>right.first)
      {
          return {left.first+1,left.second+root->data};
      }
      else if(right>left){
          return {right.first+1,right.second+root->data};
      }
      else{
         return {left.first+1,max(left.second,right.second)+root->data};
      }
     
      
  }
    int sumOfLongRootToLeafPath(Node *root) {
       return height(root).second;
    }
};
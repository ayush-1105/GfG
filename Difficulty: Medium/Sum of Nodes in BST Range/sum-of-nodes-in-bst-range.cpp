/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool exist(Node* root, int l)
  {
      if(root==NULL)return false;
      if(root->data == l)return true;
      if(root->data <l)return exist(root->right, l);
      if(root->data >l)return exist(root->left, l);
  }
  int sum(Node* root,int k)
  {
      if(root==NULL)return 0;
      int ans=0;
      if(root->data <= k)
      {
          ans+=root->data+sum(root->left,k)+sum(root->right,k);
      }
      else
      {
          ans+=sum(root->left,k);
      }
      return ans;
      
  }
    int nodeSum(Node* root, int l, int r) {
        // code here
        int ans= sum(root,r)-sum(root,l);
        if(exist(root,l))return ans+l;
        return ans;
    }
};

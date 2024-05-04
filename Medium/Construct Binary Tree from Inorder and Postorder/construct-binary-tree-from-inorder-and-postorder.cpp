//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    
    Node* createTree(int low, int high, int in[], int post[], map<int, int> &mp, int n) {
        // Base case: if low is greater than high, return nullptr indicating an empty subtree
        if (low > high) return nullptr;
        // Base case: if low is equal to high, return a new node with the value in[low]
        else if (low == high) return new Node(in[low]);
        
        int rt = -1, Postidx = -1, idx = -1;
        // Iterate over the elements in the inorder array within the range [low, high]
        for (int i = low; i <= high; ++i) {
            // Find the element in the inorder array with the highest index in the postorder array
            if (mp[in[i]] > Postidx) {
                Postidx = mp[in[i]];
                rt = in[i]; // rt contains the root value
                idx = i; // idx contains the index of the root value
            }
        }
        
        // Create a new node with the value in[idx]
        Node* root = new Node(in[idx]);
        // Recursively construct the left subtree with elements from [low, idx-1]
        root->left = createTree(low, idx - 1, in, post, mp, n);
        // Recursively construct the right subtree with elements from [idx+1, high]
        root->right = createTree(idx + 1, high, in, post, mp, n);
        
        return root; // Return the root node of the constructed subtree
    }
    
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        // Create a map to store the indices of elements in the postorder array
        map<int, int> mp;
        // Populate the map with the indices of elements in the postorder array
        for (int i = 0; i < n; ++i) {
            mp[post[i]] = i;
        }
        // Call the createTree function to construct the binary tree recursively
        return createTree(0, n - 1, in, post, mp, n);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
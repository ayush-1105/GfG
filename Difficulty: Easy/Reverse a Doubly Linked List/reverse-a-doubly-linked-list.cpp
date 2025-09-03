/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
       Node* left = head;
        Node* right = head;
        int length = 1;

        // find the length and last node
        while (right->next) {
            right = right->next;
            length++;
        }

        int l = 1, r = length;

        while (l < r) {
            // swap data
            int temp = left->data;
            left->data = right->data;
            right->data = temp;

            // move pointers
            left = left->next;
            right = right->prev;

            l++;
            r--;
        }
        return head;
    }
};
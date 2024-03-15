//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
         // Code here
         vector<int>arr;
        Node*temp=*head;
        while(temp){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        int n=arr.size();
       for(int i=0;i<n-1;i++){
           bool flag=true;
           for(int j=0;j<n-1-i;j++){
               if(arr[j]>arr[j+1]){
                   swap(arr[j],arr[j+1]);
                   flag=false;
               }
           }
           if(flag==true)break;
       }
        Node*ans=new Node(arr[0]);
        temp=ans;
        for(int i=1;i<arr.size();i++){
            temp->next=new Node(arr[i]);
            temp=temp->next;
        }
        *head=ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends
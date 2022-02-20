// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.


Node* bst(vector<int> v){
    if(v.size()==0) return NULL;
    vector<int> l,r;
    for(int i = 1; i<v.size(); i++){
        if(v[i]<v[0]) l.push_back(v[i]);
        else r.push_back(v[i]);
    }
    Node* root = new Node(v[0]);
    root->left = bst(l);
    root->right = bst(r);
    
    return root;
    
}

Node* constructBst(int arr[], int n)
{
    // Code here
    if(n==0) return NULL;
    vector<int> l,r;
    for(int i = 1; i<n; i++){
        if(arr[i]<arr[0]) l.push_back(arr[i]);
        else r.push_back(arr[i]);
    }
    Node* root = new Node(arr[0]);
    root->left = bst(l);
    root->right = bst(r);
    
    return root;
}

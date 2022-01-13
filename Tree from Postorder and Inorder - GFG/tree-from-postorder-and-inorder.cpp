// { Driver Code Starts
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

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
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

//Function to return a tree created from postorder and inoreder traversals.
unordered_map<int,int> um;
Node* solve(int in[], int post[], int &start, int istart, int iend){
    if(istart>iend) return NULL;
    Node *root = new Node(post[start]);
    int mid = um[post[start]];
    start--;
    
    root->right = solve(in, post, start, mid+1, iend);
    root->left = solve(in, post, start, istart, mid-1);
    return root;
    
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    if(!n) return NULL;
    for(int i=0; i<n; i++){
        um[in[i]] = i;
    }
    int start  = n-1;
    return solve(in, post, start, 0, n-1);
}










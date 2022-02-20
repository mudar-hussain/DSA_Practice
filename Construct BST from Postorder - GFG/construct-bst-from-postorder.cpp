// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}
// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/
int prevGreater(int post[], int l, int r){
    for(int i = l; i<r; i++)
        if(post[i]>post[r]) return i;
    return r;
}
Node* postC(int post[], int l, int r){
    if(l>r) return NULL;
    int g = prevGreater(post, l, r);
    Node* root = new Node(post[r]);
    root->left = postC(post, l, g-1);
    root->right = postC(post, g, r-1);
    return root;
    
    
}
Node *constructTree (int post[], int size)
{
//code here
    return postC(post, 0, size-1);
}
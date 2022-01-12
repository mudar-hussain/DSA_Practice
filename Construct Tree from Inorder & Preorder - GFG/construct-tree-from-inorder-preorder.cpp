// { Driver Code Starts
//

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    unordered_map<int,int> um;
    Node* solve(int in[],int pre[], int &start, int istart, int iend){
        if(iend<istart){
            return NULL;
        }
        Node *root = new Node(pre[start]);
        int mid = um[pre[start]];
        start++;
        root->left = solve(in,pre,start,istart,mid-1);
        root->right = solve(in,pre,start,mid+1,iend);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        if(!n) return NULL;
        for(int i = 0; i<n; i++){
            um[in[i]] = i;
        }
        int start = 0;
        return solve(in,pre,start, 0,n-1);
        
        
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends
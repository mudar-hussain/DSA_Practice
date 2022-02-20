// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
Node * predessor(Node *root){
        if(!root) return NULL;
        Node *cur = root->left;
        while(cur->right != NULL && cur->right != root){
            cur = cur->right;
        }
        return cur;
    }
    Node* morris(Node *current, int count, bool stage){
        if(!current) return NULL;
        int currCount = 0;
        Node *t;
        while(current != NULL){
            if(!current->left){
                currCount++;
                if(stage) count++;
                else if(currCount == count) t = current;
                current = current->right;
            }else{
                Node *pre = predessor(current);
                if(pre->right == NULL){
                    pre->right = current;
                    current = current->left;
                }
                else{
                    currCount++;
                    if(stage) count++;
                    else if(currCount == count) t = current;
                    pre->right = NULL;
                    current = current->right;
                }
            }
        }
        // cout<<"CurrCount: "<<currCount<<endl;
        if(stage)
            t = new Node(count);
        return t;
        
    }
float findMedian(struct Node *root)
{
      //Code here
      Node *t  = morris(root, 0, true);
      int count = t->data;
      if(count%2==0){
        //   cout<<count/2<<endl;
          int one = morris(root, count/2, false)->data;
        //   cout<<count/2+1<<endl;
          int two = morris(root, (count/2)+1, false)->data;
        //   cout<<one<<two;
          return (float)(one+two)/2;
      }else{
          return morris(root, (count+1)/2, false)->data;
      }
}



















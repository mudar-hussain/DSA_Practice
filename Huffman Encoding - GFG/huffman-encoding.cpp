//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    struct Node {
	        char val;
	        int freq;
	        Node* left, *right;
	        Node(char v, int f){
	            this->val = v;
	            this->freq = f;
	            left = right  = NULL;
	        }
	    };
	    
	    struct compare{
	        bool operator()(Node* a, Node* b){
	            return a->freq > b->freq;
	        }
	    };
	    
	    void print(struct Node* root, vector<string> &ans, string temp){
	        if(root == NULL)
	            return;
	        if(root->val != '#'){
	            ans.push_back(temp);
	        }
	        print(root->left, ans, temp+'0');
	        print(root->right, ans, temp+'1');
	    }
	    
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    Node* top, *left, *right;
		    priority_queue<Node*, vector<Node*>, compare> pq;
		    for(int i = 0; i<S.length(); i++){
		        pq.push(new Node(S[i], f[i]));
		    }
		    while(pq.size() != 1){
		        left = pq.top();
		        pq.pop();
		        
		        right = pq.top();
		        pq.pop();
		        
		        top = new Node('#', (left->freq+right->freq));
		        top->left = left;
		        top->right = right;
		        
		        pq.push(top);
		    }
		    
		    vector<string> ans;
		    string temp = "";
		    print(pq.top(), ans, temp);
		    return ans;
		}
};





























//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
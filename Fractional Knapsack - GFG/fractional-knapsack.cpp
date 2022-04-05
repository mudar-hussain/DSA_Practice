// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item a, Item b){
        // if((a.value/a.weight)==(b.value/b.weight)) return a.weight<b.weight;
        return ((double)a.value/a.weight)>((double)b.value/b.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, cmp);
        double ans = 0.0;
        for(int i = 0; i<n; i++){
            if(arr[i].weight<=W){
                W -= arr[i].weight;
                ans += arr[i].value;
            }else {
                if(W!=0)
                    ans +=  ((double)W * ((double)arr[i].value/arr[i].weight));
                W = 0;
                // break;
            }
            if(W==0) break;
        }
        return ans;
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
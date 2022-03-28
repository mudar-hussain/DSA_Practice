// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]

    

    

    // Function to count inversions in the array.
    long long int merge(long long arr[], long long l, long long mid, long long r){
   
        long long n1 = mid-l+1;
        long long n2 = r-mid;
        
        long long a1[n1], a2[n2];
        long long ans = 0;
        
        for(long long i = 0; i<n1; i++){
            a1[i] = arr[l+i];
        }
        for(long long i = 0; i<n2; i++){
            a2[i] = arr[mid+1+i];
        }
        long long i = 0, j = 0, k = l;
        while(i<n1 && j<n2){
            if(a1[i]<=a2[j]){
                arr[k] = a1[i];
                i++;
            }else {
                arr[k] = a2[j];
                j++;
                ans += (n1-i);
            }
            k++;
        }
        while(i<n1){
            arr[k] = a1[i];
            i++;k++;
        }
        while(j<n2){
            arr[k] = a2[j];
            j++;k++;
        }
        return ans;
    }


 long long int mergeSort(long long arr[], long long l, long long r){
    long long int ans = 0;
    if(l<r){
        long long mid = l+(r-l)/2;
        ans += mergeSort(arr,l,mid);
        ans += mergeSort(arr,mid+1,r);
        
        ans += merge(arr,l,mid,r);
        
    }
    return ans;
}
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
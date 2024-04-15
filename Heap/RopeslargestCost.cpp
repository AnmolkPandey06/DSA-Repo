//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
        for(long long int i=0; i <n;i++){
            pq.push(arr[i]);
        }
        
        long long int sum=0;
        
        while(pq.size()>1){
            long long int p1=pq.top();
            pq.pop();
            long long int p2=pq.top();
            pq.pop();
            long long int temp=p1+p2;
            sum=sum+temp;
            pq.push(temp);
            
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
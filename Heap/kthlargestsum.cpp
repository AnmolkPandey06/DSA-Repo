//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        int sum=0;
        int kcount=0;
        unordered_set <int> check;
        priority_queue< int, vector<int>, greater<int> > pq;
        int j,i;
        for(j=0;j<n;j++){
            sum=0;
            for(i=j;i<n;i++){
                sum=sum+arr[i];
                // to ensure no dublicate value goes iin set 
                
                check.insert(sum);
                if(pq.size()<k){
                    pq.push(sum);
                
                }
                else {
                    if(sum>pq.top()) {
                        int eraser=pq.top();
                        check.erase(eraser);
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
            
            
        }
        return pq.top();
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends
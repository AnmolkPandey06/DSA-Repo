//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // but here we have used queue but we need to use stack only
    // vector<int> rearrangeQueue(queue<int> &q){
    //     queue <int> temp; //took s new queue
    //     vector <int> ans;
    //     for(int i=0; i<q.size();i++){
    //         temp.push(q.front());
    //         q.pop();
    //     }
    //     while(!q.empty()){
    //         ans.push_back(temp.front());
    //         temp.pop();
    //         ans.push_back(q.front());
    //         q.pop();
    
    //     }
    //     return ans;
    // }
    vector<int> rearrangeQueue(queue<int> &q){
        stack <int> temp; //took s new queue
        vector <int> ans;
        /// putting half of the queue in stack from start
        cout<<"Size"<<q.size()<<endl;

        for(int i=0; i<=q.size()/2;i++){
            temp.push(q.front());
            q.pop();
        }

        // for(int i=0;i<=q.size();i++){
        //     int val=q.front();
        //     cout<<q.front()<<" ";
        //     q.pop();
        //     q.push(val);

        // }
        // cout<<endl;
        
        //putttinh half on back of queue
        while(!temp.empty()){
            q.push(temp.top());
            temp.pop();
        }
        
        //putting 2nd half of queue to last in quwuw again
        for(int i=0; i<=q.size()/2;i++){
            q.push(q.front());
            q.pop();
        }
        
        ///putting half on stack again to get correct
        for(int i=0; i<=q.size()/2;i++){
            temp.push(q.front());
            q.pop();
        }
        
        ///now filling the array
        
        while(!q.empty()  && !temp.empty()){
            if(!temp.empty()){
                ans.push_back(temp.top());
                temp.pop(); 
            }
            if(!q.empty()){
               ans.push_back(q.front());
               q.pop();
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
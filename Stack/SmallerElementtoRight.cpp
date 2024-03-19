#include <bits/stdc++.h>
// void solve(vector <int> &ans,stack <int> &st, int num){
   
   
//     if (st.empty() || st.top() == -1) {
//         ans.push_back(-1);
//         st.push(num);
//         return;
//     }
    
    
    
    
//     //agar num se chota hai to
//     if(st.top()<num){
//         ans.push_back(st.top());
//         st.push(num);
        
//         return ;        
//     }
//     //if num se chota hai to solve again in recursive call
//     int store=st.top();
//     st.pop();
    
//     solve(ans,st,num);

//     //pushing store again

//     st.push(store);
//     return;



// }


// void solve(vector<int> &ans, stack<int> &st,int n){
//      int top=st.top();
//      if(n>top){
//          ans.push_back(st.top());
//          st.push(n);
//          return ;
//      }
     
//      st.pop();
//      solve(ans,st,n);
//      //st.push(top);
//      return;

// }

// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//     // Initialise the stack and putting -1 in bottom
//     stack <int> st;
//     st.push(-1);
    
//     vector < int> ans;
    
//     //traversing the array from behind
    
//     for(int i=n-1; i>=0;i--){
       
//        solve(ans,st,arr[i]);
       
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }


vector <int> nextSmallerElement(vector<int> &arr,int n){
    stack <int> s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while( s.top()>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }

    return ans;
}

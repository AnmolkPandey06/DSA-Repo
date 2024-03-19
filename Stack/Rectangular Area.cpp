class Solution {
private:
//     void solveright(vector<int> &arr,vector<int> &ans, stack<int> &st,int i){
//      int top=arr[st.top()];
//      if(top!=-1 &&  arr[i]>top ){
//          ans.push_back(st.top());
//          st.push(i);
//          return ;
//      }
//      else if(top==-1){
//         ans.push_back(st.top());
//         st.push(i);
//         return ;
//      }
     
//      st.pop();
//      solveright(arr,ans,st,i);
//      //st.push(top);
//      return;

// }

// vector<int> nextSmallerrightElement(vector<int> &arr, int n)
// {
//     // Initialise the stack and putting -1 in bottom
//     stack <int> st;
//     st.push(-1);
    
//     vector < int> ans;
    
//     //traversing the array from behind
    
//     for(int i=n-1; i>=0;i--){
       
//        solveright(arr,ans,st,i);
       
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
//     }



//     void solveleft(vector <int> &arr,vector<int> &ans, stack<int> &st,int i){
//        int top=arr[st.top()];
//        if(top!=-1 && arr[i]>top){
//          ans.push_back(st.top());
//          st.push(i);
//          return ;
//        }
//        else if(top==-1){
//         ans.push_back(st.top());
//         st.push(i);
//         return ;
//      }
     
//        st.pop();
//        solveleft(arr,ans,st,i);
//      //st.push(top);
//         return;

//       }

// vector<int> nextSmallerleftElement(vector<int> &arr, int n)
// {
//     // Initialise the stack and putting -1 in bottom
//     stack <int> st;
//     st.push(-1);
    
//     vector < int> ans;
    
//     //traversing the array from behind
    
//     for(int i=0; i<arr.size();i++){
       
//        solveleft(arr,ans,st,i);
       
//     }
//     //reverse(ans.begin(), ans.end());
//     return ans;
//     }

// vector <int> nextSmallerRightElement(vector<int> &arr,int n){
//     stack <int> s;
//     s.push(-1);
//     vector<int>ans(n);

//     for(int i=n-1;i>=0;i--){
//         int curr=arr[i];
//         while(arr[i]!=-1 && arr[s.top()]>=curr){
//             s.pop();
//         }
//         ans[i]=s.top();
//         s.push(i);
//     }

//     return ans;
// }



vector <int> nextSmallerLeftElement(vector<int> arr,int n){
    stack <int> s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }

    return ans;
}


  vector<int> nextSmallerRightElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    // vector<int> nextSmallerLeftElement(vector<int> arr, int n) {
    //     stack<int> s;
    //     s.push(-1);
    //     vector<int> ans(n);

    //     for(int i=0; i<n; i++) {
    //         int curr = arr[i];
    //         while(s.top() != -1 && arr[s.top()] >= curr)
    //         {
    //             s.pop();
    //         }
    //         //ans is stack ka top
    //         ans[i] = s.top();
    //         s.push(i);
    //     }
    //     return ans; 
    // }    


public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        //making a array which contains smaller in left of the array 
        vector <int> left(n);
        left=nextSmallerLeftElement(heights,n);
        // making a array which contains smaller in right of the array
        vector<int> right(n);
        right=nextSmallerRightElement(heights,n);

        int area=INT_MIN;

        for(int i=0;i<heights.size();i++){
            int l=heights[i];
            
            if(right[i]==-1){
                right[i]=n;
            }
            int b=right[i]-left[i]-1;
            int newArea=l*b;

            area=max(area,newArea);
        }

        return area;


    }
};
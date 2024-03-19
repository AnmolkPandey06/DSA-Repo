//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    
    
  public:
    //   vector<int> nextSmallerRightElement(int *arr, int n) {
    //     stack<int> s;
    //     s.push(-1);
    //     vector<int> ans(n);

    //     for(int i=n-1; i>=0 ; i--) {
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
    
    // vector<int> nextSmallerLeftElement(int *arr, int n) {
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
     vector<int> nextSmallerRightElement(int *arr, int n) {
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
    
    vector<int> nextSmallerLeftElement(int* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
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
    
    
    
    
      
//   int largestRectangleArea(int* heights, int n) {
//         //int n= heights.size();
        
//         vector<int> next(n);
//         next = nextSmallerRightElement(heights, n);
            
//         vector<int> prev(n);
//         prev = nextSmallerLeftElement(heights, n);
        
//         int area = INT_MIN;
//         for(int i=0; i<n; i++) {
//             int l = heights[i];
            
//             if(next[i] == -1) {
//                 next[i] = n;
//             }
//              int b = next[i] - prev[i] - 1;
//             int newArea = l*b;
//             area = max(area, newArea);
//         }
//         return area;
//     }
 
  


    
    
    
    int largestRectangleArea(int *arr, int n) {
        //int n=heights.size();
        //making a array which contains smaller in left of the array 
        vector <int> left(n);
        left=nextSmallerLeftElement(arr,n);
        // making a array which contains smaller in right of the array
        vector<int> right(n);
        right=nextSmallerRightElement(arr,n);

        int area=INT_MIN;

        for(int i=0;i<n;i++){
            int l=arr[i];
            
            if(right[i]==-1){
                right[i]=n;
            }
            int b=right[i]-left[i]-1;
            int newArea=l*b;

            area=max(area,newArea);
        }

        return area;


    }
    
    
  int maxArea(int M[MAX][MAX], int n, int m) {
        
        //compute area for first row
        int area = largestRectangleArea(M[0], m);
        
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                
                //row udpate: by adding previous row's value
                if(M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i-1][j];
                else
                    M[i][j] = 0;
            }
            
            //entire row is updated now
            area = max(area, largestRectangleArea(M[i],m));
            
        }
        return area;
    }
    
    
    // int maxArea(int M[MAX][MAX], int n, int m) {
    //      // first compute for first row
    //       int area= largestRectangleArea(M[0],m);
          
    //       for(int i=1;i<n;i++){
    //           for(int j=0;j<m;j++){
    //               if(M[i][j]!=0){
    //                   M[i][j]=M[i][j]+M[i-1][j];    
    //               }
    //               else{
    //                   M[i][j]=0;
    //               }
                  
    //           }
              
    //           area=max(largestRectangleArea(M[i],m),area);
    //       }
          
          
    //       return area;
          
          
        
    // }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends